#include <stdio.h>
#include "operations.h"

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Traverse Circular Linked List\n");
        printf("3. Insert Before\n");
        printf("4. Insert After\n");
        printf("5. Delete Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                traverse();
                break;
            case 3:
                insertBefore();
                break;
            case 4:
                insertAfter();
                break;
            case 5:
                deleteElement();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
