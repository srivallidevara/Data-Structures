#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void initialize()
{
    int i;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key)
{
    int index = key % SIZE;
    int start = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        if (index == start)
        {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("%d inserted at index %d\n", key, index);
}

void search(int key)
{
    int index = key % SIZE;
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            printf("%d found at index %d\n", key, index);
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    printf("%d not found\n", key);
}

void display()
{
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("Index %d: Empty\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main()
{
    int choice, key;

    initialize();

    while (1)
    {
        printf("\n--- HASHING ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}