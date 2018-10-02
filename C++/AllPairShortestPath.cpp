// Made by Saurabh Bansal
// O(V^2) solution of All pairs shortest path problem using Flloyd Warshal's Algorithm
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main()
{
	int n, e;//No. of vettices and edges, assuming vertices are numbered from 1 to n
	cin >> n >> e;
	int adjmat[n][n], apsp[n][n];// adjmat is adjacency matrix, apsp is answer matrix where a[i][j] is shortest path between i + 1th and j + 1th vertex

	// Initialisation
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			apsp[i][j] = INF;
			adjmat[i][j] = INF;
		}

		apsp[i][i] = 0;
		adjmat[i][i] = 0;
	}

	// Input
	int f, s, w;// For edge from f to s with weight W
	for(int i = 0; i < e; i++)
	{
		cin >> f >> s >> w;
		f--;
		s--;
		adjmat[f][s] = w;
		apsp[f][s] = w;
	}

	//solution
	for(int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(apsp[i][j] > (apsp[i][k] + apsp[k][j]))
					apsp[i][j] = apsp[i][k] + apsp[k][j];
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout <<"Shortest Distance from "<< i + 1 <<" to "<< j + 1 <<" = "<< ((apsp[i][j] == INF) ? -1 : apsp[i][j]) <<"\n";
		}
	}

	return 0;
}