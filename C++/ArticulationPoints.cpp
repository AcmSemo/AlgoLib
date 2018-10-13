#include <bits/stdc++.h>
#define NIL -1
#define RED 0
#define YELLOW 1
#define GREEN 2
#define INF 999999

using namespace std;

class Graph{
    int n;
    int t = 1;
    list <int> *adj;
    vector <int> color, pi, d, f, low, ap;
    public:
    Graph(int vertices){
        n = vertices;
        adj = new list <int> [n];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int s){
        for(int u = 0; u < n; u++){
            color.push_back(RED);
            pi.push_back(NIL);
            d.push_back(0);
            f.push_back(0);
            low.push_back(NIL);
            ap.push_back(0);
        }
        for(int u = 0; u < n; u++){
            if(color[u] == RED)
                DFS_visit(u);
        }

    }

    void DFS_visit(int u){
        int children = 0;
        color[u] = YELLOW;
        d[u] = low[u] = t++;
        //cout << "discovery time of " << u << " is " << d[u] << endl;
        list <int>::iterator v;
        for(v = adj[u].begin(); v != adj[u].end(); v++){
            if(color[*v] == RED){
                children++;
                pi[*v] = u;
                DFS_visit(*v);
                low[u]  = min(low[u], low[*v]);
                if (pi[u] == NIL && children > 1)
                    ap[u] = 1;
                if (pi[u] != NIL && low[*v] >= d[u])
                    ap[u] = 1;
            }
            else if (*v != pi[u])
                low[u] = min(low[u], d[*v]);
        }
        color[u] = GREEN;
        f[u] = t++;
        //cout << "finish time of " << u << " is " << f[u] << endl;
    }

    void articulationPoints(){
        cout << "Boo" << endl;
        for(int v = 0; v < ap.size(); v++){
            if(ap[v])
                cout << v << endl;
        }
    }


};

int main(){ 
    // //Graph 1
    // Graph g(8);
    // g.addEdge(0,2);
    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,4);
    // g.addEdge(4,6);
    // g.addEdge(4,5);
    // g.addEdge(5,7);
    // g.DFS(3);

    //Graph 2
    Graph g2(5);
    g2.addEdge(0,1);
    g2.addEdge(1,2);
    g2.addEdge(2,0);
    g2.addEdge(0,3);
    g2.addEdge(3,4);
    g2.DFS(0);
    g2.articulationPoints();

    //Graph 3
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.DFS(0);
    g3.articulationPoints();
}