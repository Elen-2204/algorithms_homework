#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

typedef struct Node {
    int parent;
    int rank;
} Node;

void makeSet(Node sets[], int n) {
    for (int i = 0; i < n; i++) {
        sets[i].parent = i;
        sets[i].rank = 0;
    }
}

int find(Node sets[], int x) {
    if (sets[x].parent != x)
        sets[x].parent = find(sets, sets[x].parent);
    return sets[x].parent;
}

void unionSets(Node sets[], int x, int y) {
    int rootX = find(sets, x);
    int rootY = find(sets, y);
    if (rootX == rootY) 
        return;

    if (sets[rootX].rank < sets[rootY].rank)
        sets[rootX].parent = rootY;
    else if (sets[rootX].rank > sets[rootY].rank)
        sets[rootY].parent = rootX;
    else {
        sets[rootY].parent = rootX;
        sets[rootX].rank++;
    }
}

int main() {
    int n = 6;
    Node sets[MAX_NODES];

    makeSet(sets, n);

    int edges[][2] = { {0, 1}, {1, 2}, {3, 4} };

    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        unionSets(sets, x, y);
    }

    printf("Connected Components:\n");
    for (int i = 0; i < n; i++) {
        if (sets[i].parent == i) {
            printf("Component %d:", i);
            for (int j = 0; j < n; j++) {
                if (find(sets, j) == i)
                    printf(" %d", j);
            }
            printf("\n");
        }
    }

    return 0;
}
