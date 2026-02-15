Dijkstra's Shortest Path

Program Name: Dijkstra's Shortest Path
Language: C
Author: Anwesh Humagain
Date: 14-Feb-2026
Course: COMP202

---

(a) data structures

the program uses two global arrays and a 2D adjacency matrix passed into the main function.

dist[NODES] — stores the shortest known distance from the source to every other node. starts at INF (9999) for all nodes except the source which starts at 0.

visited[NODES] — keeps track of which nodes have already been finalized. once a node is marked 1 it means we have confirmed the shortest path to it and we will not touch it again.

the graph itself is stored as a 2D integer array where graph[i][j] holds the weight of the edge between node i and node j. a value of 0 means there is no direct connection. NODES is set to 5.

---

(b) functions

1. picknear(int dist[], int visited[], int n)
goes through all nodes and returns the index of the unvisited node with the smallest current distance. think of it as scanning your notes and picking the closest city you have not locked in yet.

2. dijkstra(int graph[NODES][NODES], int n, int source)
the main algorithm. it starts by setting all distances to INF and marking everything as unvisited, then sets the source distance to 0. each step it picks the nearest unvisited node, marks it as done, and checks if going through it gives a shorter path to any of its neighbors. if it does it updates the distance. after n-1 steps all shortest paths are finalized and printed.

---

(c) how main() works

main() sets up a 5 node graph as a hardcoded adjacency matrix with edge weights between connected nodes and 0 where there is no connection. it then calls dijkstra() with node 0 as the source. the function handles everything from there and prints the shortest distance from node 0 to every other node.

---

(d) sample output
```
vertex   distance from source
0        0
1        15
2        10
3        12
4        12
```