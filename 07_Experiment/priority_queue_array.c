#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Element {
    int data;
    int priority;
};

struct Element queue[MAX];
int size = 0;

void insert() {
    int value, priority, i;

    if (size == MAX) {
        printf("Priority Queue is full!\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    printf("Enter priority (1 = highest): ");
    scanf("%d", &priority);

    if (priority < 1) {
        printf("Invalid priority!\n");
        return;
    }

    i = size - 1;

    /* Shift lower-priority elements to the right.
       Equal priorities retain FIFO order. */
    while (i >= 0 && queue[i].priority > priority) {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1].data = value;
    queue[i + 1].priority = priority;
    size++;

    printf("Element inserted successfully.\n");
}

void deleteElement() {
    int i;

    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Deleted element: %d\n", queue[0].data);
    printf("Priority: %d\n", queue[0].priority);

    for (i = 0; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }

    size--;
}

void peek() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Highest priority element: %d\n", queue[0].data);
    printf("Priority: %d\n", queue[0].priority);
}

void display() {
    int i;

    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("\nElement\tPriority\n");
    printf("-----------------\n");

    for (i = 0; i < size; i++) {
        printf("%d\t%d\n", queue[i].data,
               queue[i].priority);
    }
}

void search() {
    int value, i;

    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &value);

    for (i = 0; i < size; i++) {
        if (queue[i].data == value) {
            printf("Element found!\n");
            printf("Priority: %d\n", queue[i].priority);
            printf("Position: %d\n", i + 1);
            return;
        }
    }

    printf("Element not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== PRIORITY QUEUE =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Search\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                deleteElement();
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