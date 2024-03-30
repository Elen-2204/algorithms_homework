#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define INFINITY 999
#define MAX 10



void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (Graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];
    }
    for (int i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INFINITY;

        for (int i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }


    for (int i = 0; i < n; i++)
        if (i != start) {
            printf("\nDistance from source to %d: %d", i, distance[i]);
        }
}
int main() {
    int Graph[MAX][MAX];
    int n, u;
    printf("Enter the number of vertices in the graph (max %d): ", MAX);
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices. Please enter a positive integer less than or equal to %d.\n", MAX);
        return 1;
    }

    printf("Enter the adjacency matrix representation of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &Graph[i][j]);
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &u);
    if (u < 0 || u >= n) {
        printf("Invalid source vertex. Please enter an integer between 0 and %d.\n", n - 1);
        return 1;
    }

    Dijkstra(Graph, n, u);

    return 0;
}

