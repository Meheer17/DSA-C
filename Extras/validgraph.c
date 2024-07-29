#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

void dfs(int v, int parent) { // Stack
    visited[v] = true;
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[v][i] == 1) {
            if (!visited[i]) {
                dfs(i, v);
            } else if (i != parent) {
                // Cycle detected
                printf("Graph is not a tree\n");
                exit(0);
            }
        }
    }
}

void bfs(int start) { // Queue
    std::queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        printf("%d ", u); // Process the current vertex

        for (int v = 0; v < MAX_VERTICES; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

bool isTree(int V) {
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1);
            count++;
        }
    }
    return (count == 1);
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isTree(numVertices)) {
        printf("Graph is a tree\n");
    } else {
        printf("Graph is not a tree\n");
    }
    return 0;
}
