#include<stdio.h>
#define NODES 5
#define INF 9999
int dist[NODES];//shortest distance from source to each node
int visited[NODES];//visited nodes
int picknear(int dist[],int visited[], int n){
    int nearest = -1;
    for(int i=0; i<NODES; i++){ //go through all nodes and skip nodes that are already visited. Pick the nearest unvisited node
        if(!visited[i] && (nearest == -1 || dist[i] < dist[nearest])){
            nearest = i;
        }
    }
    return nearest; //return the index of the nearest unvisited node
}
void dijsktra(int graph[SIZE][SIZE], int n, int source){
    //initializing distance and visited array
    for (int i = 0; i <n; i++){
        dist[i] = INF;
        visited[i] = 0;
    }

    //distance from source to itself is 0
    dist[source] = 0;

    //the main implementation
    for (int count = 0; count < n - 1; count++){
        int u = picknear(dist, visited, n);
        visited[u] = 1;

        //update distances of adjacent variables
        for (int v = 0; v <n;v++){
            if(!visited[v] &&
            graph[u][v] != 0 &&
            dist[u] != INF &&
            dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("vertex\t Distance from source\n");
    for (int i = 0; i < n; i++){
        printf("%d \t\t %d\n", i, dist[i]);
    }
}
int main(){
    int n = 5;
    int graph[NODES][NODES] = {
        {0,20,10,0,0},
        {20,0,5,1,0},
        {10,5,0,9,2},
        {0,1,9,0,4},
        {0,0,2,4,0};

    int source = 0;

    dijsktra(graph, n, source);

    return 0;
}

