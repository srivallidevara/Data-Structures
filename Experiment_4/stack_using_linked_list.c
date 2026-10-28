#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

struct Node* createNode(int value) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void push() {
    int value;
    struct Node *newNode;

    printf("Enter element to push: ");
    scanf("%d", &value);

    newNode = createNode(value);

    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack.\n", value);
}

void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    temp = top;

    printf("Deleted element: %d\n", top->data);

    top = top->next;

    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element is: %d\n", top->data);
}

void display() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    temp = top;

    printf("\nStack elements (Top to Bottom):\n");

    while (temp != NULL) {
        printf("|  %d  |\n", temp->data);
        temp = temp->next;
    }

    printf("+-------+\n");
}

void search() {
    struct Node *temp;
    int value, position = 1;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &value);

    temp = top;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d found at position %d from top.\n",
                   value, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Element not found in stack.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== STACK USING LINKED LIST =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Search\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop