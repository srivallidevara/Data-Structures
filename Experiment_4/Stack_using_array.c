#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push() {
    int value;

    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot insert element.\n");
        return;
    }

    printf("Enter element to push: ");
    scanf("%d", &value);

    top++;
    stack[top] = value;

    printf("%d pushed into stack.\n", value);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", stack[top]);
    top--;
}

void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element is: %d\n", stack[top]);
}

void display() {
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("\nStack elements (Top to Bottom):\n");

    for (i = top; i >= 0; i--) {
        printf("|  %d  |\n", stack[i]);
    }

    printf("+-------+\n");
}

void search() {
    int value, i;

    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &value);

    for (i = top; i >= 0; i--) {
        if (stack[i] == value) {
            printf("%d found at position %d from top.\n",
                   value, top - i + 1);
            return;
        }
    }

    printf("Element not found in stack.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== STACK USING ARRAY =====\n");
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
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                search();
                break;

            case 6:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}