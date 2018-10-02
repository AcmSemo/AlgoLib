// Implementation of Depth First Search using STL

#include<bits/stdc++.h> 
using namespace std; 
  
// A utility function to add an edge in an undirected graph. 
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
// A utility function to do DFS of graph recursively from a given vertex u. 
void DFSUtil(int u, vector<int> adj[], 
                    vector<bool> &visited) 
{ 
    visited[u] = true; 
    cout << u << " "; 
    for (int i=0; i<adj[u].size(); i++) 
        if (visited[adj[u][i]] == false) 
            DFSUtil(adj[u][i], adj, visited); 
} 
  
// This function does DFSUtil() for all unvisited vertices. 
void DFS(vector<int> adj[], int V) 
{ 
    vector<bool> visited(V, false); 
    for (int u=0; u<V; u++) 
        if (visited[u] == false) 
            DFSUtil(u, adj, visited); 
} 
  
int main() 
{ 
    int V = 5; 
    vector<int> adj[V]; 
  
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    cout << "DFS path : ";
    DFS(adj, V); 
    cout << endl;
    return 0; 
} 
