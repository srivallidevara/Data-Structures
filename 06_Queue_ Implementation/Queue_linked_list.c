#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

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

void enqueue() {
    int value;
    struct Node *newNode;

    printf("Enter element to insert: ");
    scanf("%d", &value);

    newNode = createNode(value);

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into queue.\n", value);
}

void dequeue() {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
       