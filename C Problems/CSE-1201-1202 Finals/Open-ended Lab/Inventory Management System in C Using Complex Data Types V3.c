#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100  // Maximum items allowed in inventory

// Structure to store each product
typedef struct {
    char productName[50];
    int stock;
    float unitPrice;
} InventoryItem;

// Global inventory array
InventoryItem items[MAX_ITEMS];
int totalItems = 0;

// Function prototypes
void addOrUpdateItem();
void deductItemQuantity();
void displayInventory();
void inventoryMenu();

int main() {
    inventoryMenu();
    return 0;
}

// Function to add new item or update existing
void addOrUpdateItem() {
    char name[50];
    int quantity;
    float price;
    int isFound = 0;

    printf("\nEnter product name: ");
    scanf(" %[^\n]", name);

    printf("Enter quantity to add: ");
    scanf("%d", &quantity);

    for (int i = 0; i < totalItems; i++) {
        if (strcmp(items[i].productName, name) == 0) {
            items[i].stock += quantity;
            printf("\n[Updated] '%s' now has %d units in stock.\n", name, items[i].stock);
            isFound = 1;
            break;
        }
    }

    if (!isFound) {
        if (totalItems < MAX_ITEMS) {
            printf("Enter price per unit: ");
            scanf("%f", &price);

            strcpy(items[totalItems].productName, name);
            items[totalItems].stock = quantity;
            items[totalItems].unitPrice = price;
            totalItems++;

            printf("\n[Added] New product '%s' with %d units at %.2f per unit.\n", name, quantity, price);
        } else {
            printf("\nInventory full! Cannot add more products.\n");
        }
    }
}

// Function to deduct quantity from a product
void deductItemQuantity() {
    char name[50];
    int quantity;
    int isFound = 0;

    printf("\nEnter product name to deduct: ");
    scanf(" %[^\n]", name);

    printf("Enter quantity to remove: ");
    scanf("%d", &quantity);

    for (int i = 0; i < totalItems; i++) {
        if (strcmp(items[i].productName, name) == 0) {
            isFound = 1;
            if (items[i].stock >= quantity) {
                items[i].stock -= quantity;
                printf("\n[Deducted] %d units removed from '%s'. Remaining stock: %d\n", quantity, name, items[i].stock);
            } else {
                printf("\n[Error] Not enough stock! Available units: %d\n", items[i].stock);
            }
            break;
        }
    }

    if (!isFound) {
        printf("\n[Error] Product '%s' not found in inventory.\n", name);
    }
}

// Function to display the current inventory
void displayInventory() {
    if (totalItems == 0) {
        printf("\nInventory is currently empty.\n");
        return;
    }

    printf("\n================ Current Inventory ================\n");
    printf("%-20s | %-10s | %-10s | %-12s\n", "Product Name", "Quantity", "Unit Price", "Total Value");
    printf("---------------------------------------------------------------\n");

    float grandTotal = 0;
    for (int i = 0; i < totalItems; i++) {
        float totalValue = items[i].stock * items[i].unitPrice;
        printf("%-20s | %-10d | %-10.2f | %-12.2f\n", items[i].productName, items[i].stock, items[i].unitPrice, totalValue);
        grandTotal += totalValue;
    }

    printf("---------------------------------------------------------------\n");
    printf("Overall Inventory Value: %.2f\n", grandTotal);
    printf("===============================================================\n\n");
}

// Main menu loop
void inventoryMenu() {
    int choice;
    do {
        printf("\n=== Inventory Management System ===\n");
        printf("1. Add / Update Product\n");
        printf("2. Deduct Product Quantity\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addOrUpdateItem();
                break;
            case 2:
                deductItemQuantity();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("\nExiting Inventory Management System. Goodbye!\n");
                break;
            default:
                printf("\nInvalid selection! Please try again.\n");
        }
    } while (choice != 4);
}
