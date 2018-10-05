#include <iostream>
#define V 4
#define INF 99999

using namespace std;

void printSoln(int D[][V]){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(D[i][j] == INF)
                cout << " INF";
            else
                cout << "  " << D[i][j];
        }
        cout << endl;
    }
}

void floydWarshall(int graph[][V], int pi[][V]){
    int D[V][V], i, j, k;

    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++){
            D[i][j] = graph[i][j];
            pi[i][j] = i;
        }

    for(k = 0; k < V; k++){
        for(i = 0; i < V; i++){
            for(j = 0; j < V; j++){
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    pi[i][j] = k;
                }
            }
        }
    }
    printSoln(D);
}

void printPath(int i, int j, int pi[][V]){
    if(pi[i][j] == i)
        cout << "(" << i << "," << j << ")" << endl;
    else{
        printPath(i,pi[i][j],pi);
        printPath(pi[i][j],j, pi);
    }
}

int main(){
    int graph[V][V] = {{  0,  5,INF, 10},
                       {INF,  0,  3,INF},
                       {INF,INF,  0,  1},
                       {INF,INF,INF,  0}};

    int pi[V][V] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

    floydWarshall(graph, pi);
    printPath(0,3,pi);
    return 0;
}