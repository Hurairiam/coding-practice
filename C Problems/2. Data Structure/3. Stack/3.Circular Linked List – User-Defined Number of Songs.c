#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct node {
    char song[50];
    struct node *next;
};

int main() {
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newNode = NULL;
    int n, i;

    printf("Enter number of songs: ");
    scanf("%d", &n);
    getchar();  // consume newline after number input

    for (i = 1; i <= n; i++) {
        // Allocate memory for new node
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter name of song %d: ", i);
        fgets(newNode->song, sizeof(newNode->song), stdin);
        newNode->song[strcspn(newNode->song, "\n")] = 0;  // remove newline

        if (head == NULL) {
            // First node points to itself
            head = newNode;
            newNode->next = head;
        } else {
            // Traverse to last node
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;  // Circular link
        }
    }

    // Traverse and print playlist
    printf("\n🎶 Songs in the Circular Playlist:\n");
    if (head != NULL) {
        temp = head;
        do {
            printf("%s -> ", temp->song);
            temp = temp->next;
        } while (temp != head);
        printf("(Back to start)\n");
    } else {
        printf("Playlist is empty.\n");
    }

    return 0;
}
