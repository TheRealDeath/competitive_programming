#include <bits/stdc++.h>
using namespace std;
 
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    void addEdge(int v, int w);
    void DFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
}
 
void Graph::DFS(int v, string s)
{
  visited[v] = true;
  s += v+" ";
  for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
      DFS(*i);
	return s;
}