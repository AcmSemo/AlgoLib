#include <bits/stdc++.h>
using namespace std;

//Graph class with dfs and bfs
class Graph
{
  int V;
  list<int> *adj;

  public:
  Graph (int V)
  {
    this->V = V;
    adj = new list<int>[V];
  }

  void add_edge (int v, int w)
  {
    adj[v].push_back(w);
  }

  void bfs (int s)
  {
    bool visited[V] = {false};
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
      s = q.front();
      q.pop();
      cout<<s<<' ';
      for (list<int>::iterator i=adj[s].begin();i!=adj[s].end();++i)
      {
        if (!visited[*i])
        {
          visited[*i] = true;
          q.push(*i);
        }
      }
    }
  }

  void dfs (int s)
  {
    bool visited[V] = {false};
    stack<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
      s = q.top();
      q.pop();
      cout<<s<<' ';
      for (list<int>::iterator i=adj[s].begin();i!=adj[s].end();++i)
      {
        if (!visited[*i])
        {
          visited[*i] = true;
          q.push(*i);
        }
      }
    }
  }
};
//end;
