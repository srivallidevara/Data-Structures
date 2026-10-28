#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning() {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning.\n");
}

void insertAtEnd() {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted at end.\n");
}

void deleteNode() {
    struct Node *temp, *prev;
    int key;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    temp = head;

    if (temp->data == key) {
        head = head->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted successfully.\n");
    }
}

void searchNode() {
    struct Node *temp;
    int key, position = 1;

    printf("Enter value to search: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value found at position %d.\n", position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Value not found.\n");
}

void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Search a Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertAtBeginning();
                break;

            case 2:
                insertAtEnd();
                break;

            case 3:
                deleteNode();
                break;

            case 4:
                searchNode();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}