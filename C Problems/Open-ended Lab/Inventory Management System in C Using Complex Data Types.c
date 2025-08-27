#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 100   // Maximum number of items in inventory

// Structure to represent one item
typedef struct {
    char itemName[50];
    int quantity;
    float cost;
} Item;

// Global array and tracker
Item stock[LIMIT];
int totalItems = 0;

// Function declarations
void insert_item();
void remove_item();
void display_inventory();
void menu();
void flush_buffer();

// Flush buffer to handle input issues
void flush_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // discard extra characters
    }
}

int main() {
    menu();
    return 0;
}

// Add new item or update existing
void insert_item() {
    char tempName[50];
    int qty;
    float price;
    int exists = 0;

    flush_buffer();
    printf("Enter item name: ");
    fgets(tempName, sizeof(tempName), stdin);
    tempName[strcspn(tempName, "\n")] = '\0';   // remove newline

    printf("Enter quantity: ");
    scanf("%d", &qty);
    flush_buffer();

    for (int i = 0; i < totalItems; i++) {
        if (strcmp(stock[i].itemName, tempName) == 0) {
            stock[i].quantity += qty;
            printf("Updated %s. New stock: %d\n", stock[i].itemName, stock[i].quantity);
            exists = 1;
            break;
        }
    }

    if (!exists) {
        if (totalItems < LIMIT) {
            printf("Enter unit price for %s: ", tempName);
            scanf("%f", &price);
            flush_buffer();

            strcpy(stock[totalItems].itemName, tempName);
            stock[totalItems].quantity = qty;
            stock[totalItems].cost = price;
            totalItems++;

            printf("Added new item: %s\n", tempName);
        } else {
            printf("Inventory is full. Cannot add more items.\n");
        }
    }
}

// Remove some units of an item
void remove_item() {
    char tempName[50];
    int qty, found = 0;

    flush_buffer();
    printf("Enter item name to remove: ");
    fgets(tempName, sizeof(tempName), stdin);
    tempName[strcspn(tempName, "\n")] = '\0';

    printf("Enter quantity to remove: ");
    scanf("%d", &qty);
    flush_buffer();

    for (int i = 0; i < totalItems; i++) {
        if (strcmp(stock[i].itemName, tempName) == 0) {
            found = 1;
            if (stock[i].quantity >= qty) {
                stock[i].quantity -= qty;
                printf("Removed %d units of %s. Remaining: %d\n",
                       qty, stock[i].itemName, stock[i].quantity);
            } else {
                printf("Not enough stock for %s.\n", stock[i].itemName);
                printf("Available: %d\n", stock[i].quantity);
            }
            break;
        }
    }

    if (!found) {
        printf("Item '%s' not found in stock.\n", tempName);
    }
}

// Display all items and total value
void display_inventory() {
    float sum = 0.0;

    if (totalItems == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\n===== Inventory List =====\n");
    for (int i = 0; i < totalItems; i++) {
        float itemValue = stock[i].quantity * stock[i].cost;
        printf("Item: %s\n", stock[i].itemName);
        printf(" Quantity: %d\n", stock[i].quantity);
        printf(" Price: %.2f\n", stock[i].cost);
        printf(" Value: %.2f\n", itemValue);
        printf("---------------------------\n");
        sum += itemValue;
    }

    printf("Total Inventory Value: %.2f\n\n", sum);
}

// Menu loop
void menu() {
    int option;
    do {
        printf("\n=== Inventory Management Menu ===\n");
        printf("1. Insert/Update Item\n");
        printf("2. Remove Item\n");
        printf("3. Show Inventory\n");
        printf("4. Exit\n");
        printf("Choose option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insert_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 4);
}
