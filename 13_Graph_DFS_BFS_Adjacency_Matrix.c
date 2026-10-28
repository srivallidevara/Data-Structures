#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

/* BFS Traversal */
void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;
    int i, vertex;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        vertex = queue[front++];
        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

/* DFS Traversal - Non-recursive */
void DFS(int start)
{
    int stack[MAX];
    int top = -1;
    int i, vertex;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    stack[++top] = start;

    printf("DFS Traversal: ");

    while (top != -1)
    {
        vertex = stack[top--];

        if (!visited[vertex])
        {
            printf("%d ", vertex);
            visited[vertex] = 1;

            /* Reverse order to visit smaller index first */
            for (i = n - 1; i >= 0; i--)
            {
                if (graph[vertex][i] == 1 && !visited[i])
                    stack[++top] = i;
            }
        }
    }

    printf("\n");
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Number of vertices must be between 1 and %d\n", MAX);
        return 0;
    }

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting vertex\n");
        return 0;
    }

    BFS(start);
    DFS(start);

    return 0;
}