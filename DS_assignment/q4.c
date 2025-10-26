// The Registrar's office at a university needs to design a system to manage student
// records. This system must efficiently handle various tasks related to student data,
// including enrollment, grade management, and student information lookup. The
// core of this system will involve storing a collection of student records, where each
// record contains multiple pieces of related information.
// Task
// Your task is to design and implement a data structure for a student records system.
// You must define a struct to represent a single student and use it to build a data
// management system that meets the following requirements:
// Part 1: struct definition
// Define a struct named Student.
// The Student struct must contain the following members:
// a. b. c. d. e. student_id: A unique integer to identify each student.
// first_name: A string for the student's first name.
// last_name: A string for the student's last name.
// gpa: A floating-point number for the student's grade point average.
// major: A string indicating the student's major.
// Part 2: Dynamic data storage
// The system will handle an unknown number of students over time. An array with a
// fixed size is not an ideal solution, as it would be inefficient for memory use and
// inflexible for managing a changing number of students. You must choose and
// implement a dynamic data structure to hold a collection of Student structs.
// Part 3: Required operations
// Implement the following functions to manage the student records:
// add_student(): A function that takes student information as input and adds a new
// Student struct to your collection.
// delete_student(): A function that removes a student's record from the collection
// based on their student_id.
// find_student_by_id(): A function that searches for and displays a student's
// information, given their student_id.
// print_all_students(): A function that displays the information for all students
// currently in the system.
// get_gpa_average(): A function that calculates and returns the average GPA of all
// students in the collection.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int student_id;
    char first_name[50];
    char last_name[50];
    float gpa;
    char major[50];
} Student;

typedef struct Node {
    Student data;
    struct Node* next;
} Node;

Node* head = NULL;

void add_student(int id, const char* first, const char* last, float gpa, const char* major) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    new_node->data.student_id = id;
    strcpy(new_node->data.first_name, first);
    strcpy(new_node->data.last_name, last);
    new_node->data.gpa = gpa;
    strcpy(new_node->data.major, major);

    new_node->next = head;
    head = new_node;

    printf("Student %d added.\n", id);
}

void delete_student(int id) {
    Node* current = head;
    Node* prev = NULL;

    if (current != NULL && current->data.student_id == id) {
        head = current->next;
        free(current);
        printf("Student %d deleted.\n", id);
        return;
    }

    while (current != NULL && current->data.student_id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student %d not found.\n", id);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Student %d deleted.\n", id);
}

void find_student_by_id(int id) {
    Node* current = head;
    while (current != NULL) {
        if (current->data.student_id == id) {
            printf("\n--- Student Found ---\n");
            printf("ID:       %d\n", current->data.student_id);
            printf("Name:     %s %s\n", current->data.first_name, current->data.last_name);
            printf("GPA:      %.2f\n", current->data.gpa);
            printf("Major:    %s\n", current->data.major);
            printf("---------------------\n");
            return;
        }
        current = current->next;
    }
    printf("Student %d not found.\n", id);
}

void print_all_students() {
    Node* current = head;
    if (current == NULL) {
        printf("No students in the system.\n");
        return;
    }

    printf("\n--- All Student Records ---\n");
    while (current != NULL) {
        printf("ID:       %d\n", current->data.student_id);
        printf("Name:     %s %s\n", current->data.first_name, current->data.last_name);
        printf("GPA:      %.2f\n", current->data.gpa);
        printf("Major:    %s\n", current->data.major);
        printf("---------------------------\n");
        current = current->next;
    }
}

float get_gpa_average() {
    float total_gpa = 0.0;
    int count = 0;
    Node* current = head;

    if (head == NULL) {
        return 0.0;
    }

    while (current != NULL) {
        total_gpa += current->data.gpa;
        count++;
        current = current->next;
    }

    return total_gpa / (float)count;
}

void free_list() {
    Node* current = head;
    Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    head = NULL;
}

int main() {
    add_student(101, "Alice", "Smith", 3.8, "Computer Science");
    add_student(102, "Bob", "Johnson", 3.5, "Physics");
    add_student(103, "Charlie", "Brown", 3.2, "History");

    print_all_students();

    find_student_by_id(102);
    find_student_by_id(999);

    printf("\nAverage GPA: %.2f\n\n", get_gpa_average());

    delete_student(102);
    delete_student(101);

    print_all_students();

    printf("\nNew Average GPA: %.2f\n", get_gpa_average());

    add_student(104, "David", "Lee", 4.0, "Mathematics");

    print_all_students();

    free_list();
    return 0;
}
