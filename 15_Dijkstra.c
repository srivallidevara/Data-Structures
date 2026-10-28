#include <stdio.h>

#define MAX 10
#define INF 99999

int main()
{
    int graph[MAX][MAX];
    int distance[MAX], visited[MAX];
    int n, source;
    int i, j, count, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of vertices\n");
        return 0;
    }

    printf("Enter adjacency matrix:\n");
    printf("(Enter %d for no edge)\n", INF);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    if (source < 0 || source >= n)
    {
        printf("Invalid source vertex\n");
        return 0;
    }

   