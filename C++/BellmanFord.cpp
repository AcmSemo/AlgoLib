#include <bits/stdc++.h>
#define INF 999999

using namespace std;

class Graph{
    int n;
    vector < pair <int,int>> edgeList;
    vector <int> d, pi, *w;
    public:
    Graph(int vertices){
        n = vertices;
        w = new vector <int> [n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                w[i].push_back(INF);
            }
        }
    }

    void addEdge(int u, int v, int weight){
        edgeList.push_back(make_pair(u,v));
        //edgeList.push_back(make_pair(v,u));
        w[u][v] = weight;
        //w[v][u] = weight;
    }

    void bellmanFord(int s){
        for(int i = 0; i < n; i++){
            d.push_back(INF);
            pi.push_back(i);
        }

        d[s] = 0;
        for(int loop = 0; loop < n-1; loop++){
            for(int i = 0; i < edgeList.size(); i++){
                int u, v;
                u = edgeList[i].first;
                v = edgeList[i].second;
                if(d[v] > d[u] + w[u][v]){
                    d[v] = d[u] + w[u][v];
                    pi[v] = u;
                }
            }
        }
    }

    void printPath(int v){
        if(pi[v] == v)
            cout << v << endl;
        else{
            printPath(pi[v]);
            cout << "(" << pi[v] << "," << v << ")" << endl;
        }
    }

    void printDistance(int s){
        bellmanFord(s);
        for(int u = 0; u < n; u++)
            cout << "Distance of " << u << " from " << s << " is " << d[u] << endl;
    }

    void detectNegativeCycle(int s){
        bellmanFord(s);
        vector <int> new_d;
        new_d = d;
        for(int i = 0; i < edgeList.size(); i++){
            int u, v;
            u = edgeList[i].first;
            v = edgeList[i].second;
            if(new_d[v] > new_d[u] + w[u][v]){
                new_d[v] = new_d[u] + w[u][v];
                pi[v] = u;
            }
        }

        for(int i = 0; i < n; i++){
            if(d[i] != new_d[i]){
                cout << "Negative weight cycle detected!!" << endl;
                break;
            }
        }


    }
};

int main(){
    Graph g(5);
    g.addEdge(4,3,1);
    g.addEdge(3,4,2);
    g.addEdge(2,4,4);
    g.addEdge(0,2,5);
    g.addEdge(1,2,-3);
    g.addEdge(0,3,8);
    g.addEdge(0,1,4);

    // g.bellmanFord(2);
    // g.printPath(3);
    // g.printDistance(0);
    
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,3);
    // g.addEdge(2,3,2);
    // g.addEdge(3,1,-6);
    g.detectNegativeCycle(0);    
}