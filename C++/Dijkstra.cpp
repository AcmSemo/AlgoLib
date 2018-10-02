// Made by Saurabh Bansal
// O(v log v) implementation of Dijkstra's Algorithm
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

void Dijkstra(vector < vector < pair <int, int> > > &adjlist, int n, int source, vector <int> &distance)
{
	set < pair <int, int> > st;
	st.insert(make_pair(0, source));
	distance[source] = 0;

	while(!st.empty())
	{
		auto x = st.begin();
		auto y = *x;
		st.erase(x);

		if(distance[y.second] < y.first)
			continue;

		for(int i = 0; i < adjlist[y.second].size(); i++)
		{
			auto p = adjlist[y.second][i];

			if(distance[p.first] > (y.first + p.second))
			{
				distance[p.first] = y.first + p.second;
				st.insert(make_pair(distance[p.first], p.first));
			}
		}
	}
}

int main()
{
	int n, e;// n is Number of vertices, assuming vertices are numbered from 1 to n, e is Number of edges
	cin >> n;
	cin >> e;
	vector < vector < pair <int, int> > > adjlist(n);// adjacency list
	int f, s, w;// For edge from f to s with weight W

	for(int i = 0; i < e; i++)
	{
		cin >> f >> s >> w;
		f--;
		s--;
		adjlist[f].push_back(make_pair(s, w));
	}

	int source;// s is source
	cin >> source;
	source--;
	vector <int> distance(n, INF);
	Dijkstra(adjlist, n, source, distance);

	for(int i = 0; i < n; i++)
	{
		cout <<"Shortest distance of "<< i + 1 <<" from source is " << distance[i] << endl ;
	}

	return 0;
}