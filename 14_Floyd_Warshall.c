#include <stdio.h>

#define MAX 10
#define INF 99999

int main()
{
    int graph[MAX][MAX];
    int n, i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    printf("(Enter %d for no edge)\n", INF);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    /* Floyd-Warshall Algorithm */
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][k] != INF &&
                    graph[k][j] != INF &&
                    graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] =
                        graph[i][k] + graph[k][j];
                }
            }
        }
    }

    printf("\nShortest Distance Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == INF)
                printf("INF