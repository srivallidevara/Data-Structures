#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertBeginning(int value) {
    struct Node *newNode = createNode(value);

    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }

    head = newNode;

    printf("%d inserted at beginning.\n", value);
}

void insertEnd(int value) {
    struct Node *newNode = createNode(value);
    struct Node *temp;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("%d inserted at end.\n", value);
}

void insertAfter(int key, int value) {
    struct Node *temp = head;
    struct Node *newNode;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the list.\n", key);
        return;
    }

    newNode = createNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    printf("%d inserted after %d.\n", value, key);
}

void deleteValue(int key) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the list.\n", key);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("%d deleted successfully.\n", key);
}

void searchValue(int key) {
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found at position %d.\n",
                   key, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("%d not found in the list.\n", key);
}

void displayForward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Forward: NULL <-> ");

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL) {
            printf(" <-> ");
        }

        temp = temp->next;
    }

    printf(" <-> NULL\n");
}

void displayReverse() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Reverse: NULL <-> ");

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->prev != NULL) {
            printf(" <-> ");
        }

        temp = temp->prev;
    }

    printf(" <-> NULL\n");
}

int main() {
    int choice, value, key;

    while (1) {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Value\n");
        printf("4. Delete a Value\n");
        printf("5. Search a Value\n");
        printf("6. Display Forward\n");
        printf("7. Display Reverse\n");
        printf("8. Exit\n");

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
                displayForward();
                break;

            case 7:
                displayReverse();
                break;

            case 8:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}