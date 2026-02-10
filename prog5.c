#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max_vertices 10 //maximum vertices
typedef struct {
    int numvertices;
    int connections[MAX_VERTICES][MAX_VERTICES];  //1 if there is a connection, 0 otherwise
} graph;
//create a graph with n vertices
graph* creategraph(int n) {
    graph* g = (graph*)malloc(sizeof(graph));
    g->numvertices = n;
    
    //initialize all connections to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->connections[i][j] = 0;
        }
    }
    return g;
}
//add an edge between vertices u and v
//in undirected graph, we need to connect both uv and vu
void addedge(graph* g, int u, int v) {
    g->connections[u][v] = 1;  //connect uv
    g->connections[v][u] = 1;  //connect vu (undirected)
}
void bfs(graph* g, int startvertex) {
    bool visited[max_vertices] = {false};  //track visited vertices
    int queue[max_vertices];               //queue for bfs
    int front = 0, rear = 0;    
    
   
    visited[startvertex] = true;
    queue[rear++] = startvertex;
    
    printf("bfs starting from vertex %d: ", startvertex);

    while (front < rear) {
        int current = queue[front++]; 
        printf("%d ", current);
        
        //check all neighbors of current vertex
        for (int neighbor = 0; neighbor < g->numvertices; neighbor++) {
            //if there's an edge AND neighbor not visited yet
            if (g->connections[current][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear++] = neighbor;
            }
        }
    }
    printf("\n");
}
//helper function for dfs
void dfsHelper(graph* g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    for (int neighbor = 0; neighbor < g->numvertices; neighbor++) {
        if (g->connections[vertex][neighbor] && !visited[neighbor]) {
            dfsHelper(g, neighbor, visited);
        }
    }
}
//main dfs function
void dfs(graph* g, int startvertex) {
    bool visited[max_vertices] = {false};  
    
    printf("dfs starting from vertex %d: ", startvertex);
    dfsHelper(g, startvertex, visited);
    printf("\n");
}
//function to print the adjacency matrix of the graph
void printgraph(graph* g) {
    printf("\nadjancent matrix for undirected graph:\n");
    printf("   ");
    for (int i = 0; i < g->numvertices; i++) printf("%d ", i);
    printf("\n");
    
    for (int i = 0; i < g->numvertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->numvertices; j++) {
            printf("%d ", g->connections[i][j]);
        }
        printf("\n");
    }
}
int main() {
    graph* g = creategraph(5);
    addedge(g, 0, 1);
    addedge(g, 0, 2);
    addedge(g, 1, 2);
    addedge(g, 1, 3);
    addedge(g, 2, 4);
    addedge(g, 3, 4);

    printgraph(g);
    bfs(g, 0);
    dfs(g, 0);
    bfs(g, 3);
    free(g);
    return 0;
}




