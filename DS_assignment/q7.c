// //Consider a music player application where users can create playlists, navigate through songs, and repeat the entire playlist. Design a data structure to efficiently manage the songs within a single playlist, allowing for seamless forward and backward navigation, as well as continuous playback (looping).
// Case Study:
// You are tasked with implementing a Playlist class using a Circular Doubly Linked List. Each node in the list will represent a Song object, containing attributes such as title, artist, and duration.
// Tasks:
// Implement the Song Class: Define a Song class with appropriate attributes and a constructor.
// Implement the Playlist Class:
// a.
// Node Structure: Define the node structure for the circular doubly linked list, including data (a Song object), next pointer, and prev pointer.
// b.
// addSong(song): Add a new song to the end of the playlist.
// c.
// removeSong(title): Remove a song by its title from the playlist. Handle cases where the song is not found or the playlist becomes empty.
// d.
// playNext(): Advance to the next song in the playlist. If at the end, loop back to the beginning.
// e.
// playPrevious(): Go back to the previous song in the playlist. If at the beginning, loop to the end.
// f.
// displayPlaylist(): Print the details of all songs in the playlist in their current order.
// Demonstrate Functionality:
// g.
// Create a Playlist instance.
// h.
// Add at least five Song objects to the playlist.
// i.
// Demonstrate playNext() and playPrevious() operations multiple times, showing the circular nature.
// j.
// Remove a song from the middle of the playlist and demonstrate navigation again.
// k.
// Display the final state of the playlist.
// Example Scenario:
// Imagine a playlist with songs A, B, C, D, E.
// Playing next from E should lead to A.
// Playing previous from A should lead to E.
// Removing song C should result in a playlist A, B, D, E, and playing next from B should lead to D.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char artist[100];
    int duration_seconds;
} Song;

typedef struct Node {
    Song data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* current_song;
    int count;
} Playlist;

Playlist* create_playlist() {
    Playlist* pl = (Playlist*)malloc(sizeof(Playlist));
    if (pl == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }
    pl->current_song = NULL;
    pl->count = 0;
    return pl;
}

void add_song(Playlist* pl, Song song) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    new_node->data = song;

    if (pl->current_song == NULL) {
        pl->current_song = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        Node* tail = pl->current_song->prev;

        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = pl->current_song;
        pl->current_song->prev = new_node;
    }
    pl->count++;
    printf("Added: %s by %s\n", song.title, song.artist);
}

void remove_song(Playlist* pl, const char* title) {
    if (pl->current_song == NULL) {
        printf("Playlist is empty. Cannot remove.\n");
        return;
    }

    Node* iterator = pl->current_song;
    Node* node_to_delete = NULL;

    for (int i = 0; i < pl->count; i++) {
        if (strcmp(iterator->data.title, title) == 0) {
            node_to_delete = iterator;
            break;
        }
        iterator = iterator->next;
    }

    if (node_to_delete == NULL) {
        printf("Song '%s' not found.\n", title);
        return;
    }

    if (pl->count == 1) {
        pl->current_song = NULL;
    } else {
        Node* prev_node = node_to_delete->prev;
        Node* next_node = node_to_delete->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;

        if (pl->current_song == node_to_delete) {
            pl->current_song = next_node;
        }
    }

    printf("Removed: %s\n", node_to_delete->data.title);
    free(node_to_delete);
    pl->count--;
}

void play_next(Playlist* pl) {
    if (pl->current_song == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    pl->current_song = pl->current_song->next;
    printf("Now playing: %s by %s\n", pl->current_song->data.title, pl->current_song->data.artist);
}

void play_previous(Playlist* pl) {
    if (pl->current_song == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    pl->current_song = pl->current_song->prev;
    printf("Now playing: %s by %s\n", pl->current_song->data.title, pl->current_song->data.artist);
}

void display_playlist(Playlist* pl) {
    if (pl->current_song == NULL) {
        printf("\nPlaylist is empty.\n");
        return;
    }

    printf("\n--- Playlist (Total: %d songs) ---\n", pl->count);
    Node* iterator = pl->current_song;

    for (int i = 0; i < pl->count; i++) {
        int minutes = iterator->data.duration_seconds / 60;
        int seconds = iterator->data.duration_seconds % 60;

        printf("  - %s by %s (%d:%02d)",
            iterator->data.title,
            iterator->data.artist,
            minutes,
            seconds);

        if (iterator == pl->current_song) {
            printf("  <-- (Current)");
        }
        printf("\n");

        iterator = iterator->next;
    }
    printf("-----------------------------------\n");
}

void free_playlist(Playlist* pl) {
    if (pl == NULL) return;

    if (pl->current_song != NULL) {
        Node* iterator = pl->current_song;
        for (int i = 0; i < pl->count; i++) {
            Node* to_free = iterator;
            iterator = iterator->next;
            free(to_free);
        }
    }
    free(pl);
}

int main() {
    Playlist* my_playlist = create_playlist();

    printf("--- (h) Adding 5 songs ---\n");
    add_song(my_playlist, (Song){"Song A", "Artist A", 354});
    add_song(my_playlist, (Song){"Song B", "Artist B", 390});
    add_song(my_playlist, (Song){"Song C", "Artist C", 482});
    add_song(my_playlist, (Song){"Song D", "Artist D", 301});
    add_song(my_playlist, (Song){"Song E", "Artist E", 233});

    display_playlist(my_playlist);

    printf("\n--- (i) Demonstrate playNext() ---\n");
    play_next(my_playlist);
    play_next(my_playlist);

    printf("\n--- (i) Demonstrate playPrevious() ---\n");
    play_previous(my_playlist);

    printf("\n--- (i) Demonstrate circularity (previous from start) ---\n");
    printf("Currently at: %s\n", my_playlist->current_song->data.title);
    play_previous(my_playlist);
    play_previous(my_playlist);

    printf("\n--- (i) Demonstrate circularity (next from end) ---\n");
    play_next(my_playlist);

    display_playlist(my_playlist);

    printf("\n--- (j) Remove song from middle ---\n");
    remove_song(my_playlist, "Song C");

    display_playlist(my_playlist);

    printf("\n--- (j) Demonstrate navigation after removal ---\n");
    printf("Currently at: %s\n", my_playlist->current_song->data.title);
    printf("Playing next (should skip removed song)...\n");
    play_next(my_playlist);
    printf("Playing previous (should skip removed song)...\n");
    play_previous(my_playlist);

    printf("\n--- (k) Final Playlist State ---\n");
    display_playlist(my_playlist);

    free_playlist(my_playlist);

    return 0;
}

