#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

struct Node* createNode(int value) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void insertBeginning(int value) {
    struct Node *newNode = createNode(value);

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }

    printf("%d inserted at beginning.\n", value);
}

void insertEnd(int value) {
    struct Node *newNode = createNode(value);

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("%d inserted at end.\n", value);
}

void insertAfter(int key, int value) {
    struct Node *temp;
    struct Node *newNode;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    do {
        if (temp->data == key) {
            newNode = createNode(value);

            newNode->next = temp->next;
            temp->next = newNode;

            if (temp == last) {
                last = newNode;
            }

            printf("%d inserted after %d.\n", value, key);
            return;
        }

        temp = temp->next;

    } while (temp != last->next);

    printf("%d not found.\n", key);
}

void deleteValue(int key) {
    struct Node *current;
    struct Node *previous;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    current = last->next;
    previous = last;

    do {
        if (current->data == key) {

            if (current == last && current->next == last) {
                last = NULL;
            } else {
                previous->next = current->next;

                if (current == last) {
                    last = previous;
                }
            }

            free(current);
            printf("%d deleted successfully.\n", key);
            return;
        }

        previous = current;
        current = current->next;

    } while (current != last->next);

    printf("%d not found.\n", key);
}

void searchValue(int key) {
    struct Node *temp;
    int position = 1;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    do {
        if (temp->data == key) {
            printf("%d found at position %d.\n",
                   key, position);
            return;
        }

        temp = temp->next;
        position++;

    } while (temp != last->next);

    printf("%d not found.\n", key);
}

void display() {
    struct Node *temp;

    if (last == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to head)\n");
}

int main() {
    int choice, value, key;

    while (1) {
        printf("\n===== CIRCULAR LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Value\n");
        printf("4. Delete a Value\n");
        printf("5. Search a Value\n");
        printf("6. Display List\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter existing value: ");
                scanf("%d", &key);
                printf("Enter new value: ");
                scanf("%d", &value);
                insertAfter(key, value);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteValue(key);
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &key);
                searchValue(key);
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}