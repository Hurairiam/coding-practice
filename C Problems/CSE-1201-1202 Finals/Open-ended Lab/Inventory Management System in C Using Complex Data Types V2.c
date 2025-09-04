#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100   // maximum capacity of the store

// Structure for each product
typedef struct {
    char name[50];
    int qty;
    float price;
} Product;

// Global array
Product inventory[MAX_ITEMS];
int itemCount = 0;

// Function prototypes
void add_product();
void delete_product();
void show_inventory();
void main_menu();

int main() {
    main_menu();
    return 0;
}

// Function to add a new product or update existing
void add_product() {
    char temp[50];
    int q;
    float p;
    int found = 0;

    printf("Enter product name: ");
    scanf(" %[^\n]", temp);

    printf("Enter quantity: ");
    scanf("%d", &q);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, temp) == 0) {
            inventory[i].qty += q;
            printf("Updated '%s'. Current stock: %d\n", temp, inventory[i].qty);
            found = 1;
            break;
        }
    }

    if (!found) {
        if (itemCount < MAX_ITEMS) {
            printf("Enter unit cost: ");
            scanf("%f", &p);

            strcpy(inventory[itemCount].name, temp);
            inventory[itemCount].qty = q;
            inventory[itemCount].price = p;
            itemCount++;

            printf("Added new product: %s\n", temp);
        } else {
            printf("Store is full. Cannot add more products.\n");
        }
    }
}

// Function to remove quantity from a product
void delete_product() {
    char temp[50];
    int q;
    int found = 0;

    printf("Enter product name to deduct: ");
    scanf(" %[^\n]", temp);

    printf("Enter quantity to deduct: ");
    scanf("%d", &q);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, temp) == 0) {
            found = 1;
            if (inventory[i].qty >= q) {
                inventory[i].qty -= q;
                printf("%d units removed from '%s'. Remaining: %d\n",
                       q, inventory[i].name, inventory[i].qty);
            } else {
                printf("Insufficient stock. Available: %d\n", inventory[i].qty);
            }
            break;
        }
    }

    if (!found) {
        printf("Product '%s' not found in inventory.\n", temp);
    }
}

// Function to display the full inventory
void show_inventory() {
    float total = 0;

    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\n---- Current Inventory ----\n");
    for (int i = 0; i < itemCount; i++) {
        float worth = inventory[i].qty * inventory[i].price;
        printf("Product: %s\n", inventory[i].name);
        printf(" Quantity: %d\n", inventory[i].qty);
        printf(" Price: %.2f\n", inventory[i].price);
        printf(" Total Value: %.2f\n", worth);
        printf("---------------------------\n");
        total += worth;
    }
    printf("Overall Inventory Value = %.2f\n\n", total);
}

// Main menu loop
void main_menu() {
    int choice;
    do {
        printf("\n=== Store Management ===\n");
        printf("1. Add/Update Product\n");
        printf("2. Deduct Product\n");
        printf("3. View Inventory\n");
        printf("4. Quit\n");
        printf("Select option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                delete_product();
                break;
            case 3:
                show_inventory();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
}
