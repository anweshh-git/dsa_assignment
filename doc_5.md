Graph BFS and DFS

Program Name: Graph BFS and DFS
Language: C
Author: Anwesh Humagain
Date: 14-Feb-2026
Course: COMP202

---

(a) data structures

the program stores the graph as an adjacency matrix inside a struct.
```c
typedef struct {
    int numvertices;
    int connections[MAX_VERTICES][MAX_VERTICES];
} graph;
```

numvertices just keeps track of how many vertices the graph has. connections is a 2D array where connections[i][j] is 1 if vertex i and vertex j are connected and 0 if they are not. MAX_VERTICES is set to 10.

since this is an undirected graph, if i connects to j then j connects to i as well, so both sides of the matrix always match.

inside bfs and dfs the program also uses plain integer arrays as a queue and a stack respectively. nothing fancy, just arrays with index variables to keep track of the front and top.

---

(b) functions

1. creategraph(int n)
sets up a new graph with n vertices. allocates memory for the struct and fills every cell in the connections matrix with 0 so it starts with no edges.

2. addedge(graph* g, int u, int v)
connects two vertices by setting connections[u][v] and connections[v][u] to 1. both sides are set since the graph is undirected.

3. bfs(graph* g, int startvertex)
starts from a given vertex and visits everything reachable level by level using a queue. the starting vertex goes in first, then for each vertex it pulls out it checks all neighbors and adds the unvisited ones to the back of the queue. keeps going until the queue is empty.

4. dfs(graph* g, int startvertex)
starts from a given vertex and goes as deep as possible before backtracking, using a stack. the starting vertex goes on the stack first. it pops from the top, and if that vertex has not been visited yet it marks it, prints it and pushes its unvisited neighbors on. neighbors go in reverse order so the output comes out in natural order.

5. printgraph(graph* g)
prints the adjacency matrix with vertex numbers along the top and left side so you can easily see which vertices are connected to which.

---

(c) how main() works

main() creates a graph with 5 vertices and adds 6 edges between them. it prints the adjacency matrix first so you can see the layout. then it runs bfs from vertex 0, dfs from vertex 0, and bfs again from vertex 3 to show what the traversal looks like from a different starting point. at the end it frees the memory.

---

(d) sample output

test case 1 — bfs from vertex 0
visits everything level by level starting from 0.

test case 2 — dfs from vertex 0
goes deep down one path first before coming back.

test case 3 — bfs from vertex 3
same bfs but from a different starting point.
```
adjacency matrix:
   0 1 2 3 4
0: 0 1 1 0 0
1: 1 0 1 1 0
2: 1 1 0 0 1
3: 0 1 0 0 1
4: 0 0 1 1 0

bfs starting from vertex 0: 0 1 2 3 4
dfs starting from vertex 0: 0 1 2 4 3
bfs starting from vertex 3: 3 1 4 0 2
```