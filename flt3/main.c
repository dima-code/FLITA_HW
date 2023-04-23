#include <stdio.h>
#include <stdbool.h>

#define MAXN 100

bool visited[MAXN];
int graph[MAXN][MAXN];
int n;

void DFS(int u) {
    visited[u] = true;
    for (int v = 0; v < n; v++) {
        if (graph[u][v] != 0 && !visited[v]) {
            DFS(v);
        }
    }
}

bool isConnected() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    DFS(0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

void visualizeGraph() {
    FILE *output = fopen("graph.dot", "w");
    fprintf(output, "graph {\n");
    for (int i = 0; i < n; i++) {
        fprintf(output, "    %d;\n", i + 1);
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0) {
                fprintf(output, "    %d -- %d [label=%d];\n", i + 1, j + 1, graph[i][j]);
            }
        }
    }
    fprintf(output, "}\n");
    fclose(output);
    printf("Graph saved in graph.dot file.\n");
}


int main() {
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }
    char c;
    int i = 0, j = 0;
    while (!feof(input)) {
        c = fgetc(input);
        if (c == ' ' || c == '\n') {
            j++;
        }
        if (c == '\n') {
            i++;
            if (j > n) {
                n = j;
            }
            j = 0;
        }
        if (c >= '0' && c <= '9') {
            ungetc(c, input);
            fscanf(input, "%d", &graph[i][j]);
        }
    }
    fclose(input);

    if (isConnected()) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    visualizeGraph();

    return 0;
}
