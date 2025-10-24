#include <stdio.h>
#include <stdlib.h>

// i) Node structure for a polynomial term
struct Term {
    int coeff;
    int exp;
    struct Term *prev;
    struct Term *next;
};

/**
 * @brief Inserts a new term at the end of a polynomial list.
 * @param head A pointer to the head pointer of the polynomial list.
 * @param coeff The coefficient of the term.
 * @param exp The exponent of the term.
 */
void insertTerm(struct Term **head, int coeff, int exp) {
    // Create the new term
    struct Term *newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;

    // If the list is empty, make the new term the head
    if (*head == NULL) {
        newTerm->prev = NULL;
        *head = newTerm;
        return;
    }

    // Otherwise, find the last term and append the new one
    struct Term *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newTerm;
    newTerm->prev = last;
}

/**
 * @brief Displays a polynomial.
 * @param head The head of the polynomial list.
 */
void display(struct Term *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Term *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief ii) Adds two polynomials.
 * @param p1 Head of the first polynomial.
 * @param p2 Head of the second polynomial.
 * @return Head of the resulting sum polynomial.
 */
struct Term* addPolynomials(struct Term *p1, struct Term *p2) {
    struct Term *sum = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertTerm(&sum, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p2->exp > p1->exp) {
            insertTerm(&sum, p2->coeff, p2->exp);
            p2 = p2->next;
        } else { // Exponents are equal
            insertTerm(&sum, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Add remaining terms from p1 or p2
    while (p1 != NULL) {
        insertTerm(&sum, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(&sum, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return sum;
}

// Main function to drive the program
int main() {
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;
    struct Term *sum = NULL;

    // Create first polynomial: 5x^2 + 4x^1 + 2x^0
    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 2, 0);

    // Create second polynomial: -5x^1 - 5x^0
    insertTerm(&poly2, -5, 1);
    insertTerm(&poly2, -5, 0);

    // iii) Display all three polynomials
    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    sum = addPolynomials(poly1, poly2);

    printf("Sum         : ");
    display(sum);

    return 0;
}
