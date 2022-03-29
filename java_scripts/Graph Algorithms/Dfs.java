import java.io.*;
import java.util.*;
class Graph 
{
  private int V;
  private LinkedList<Integer> adj[];
	Graph(int v)
  {
    V = v;
    adj = new LinkedList[v];
    for (int i = 0; i < v; ++i) adj[i] = new LinkedList();
  }
  void addEdge(int v, int w)
  {
  	adj[v].add(w);
		adj[w].add(v);
  }
  void DFSUtil(int v, boolean visited[], String s)
  {
    visited[v] = true;
    s += v+" ";
    Iterator<Integer> i = adj[v].listIterator();
    while (i.hasNext()) 
		{
      int n = i.next();
      if (!visited[n])
        DFSUtil(n, visited);
    }
		return s.trim();
  }
  void DFS(int v)
  {
    boolean visited[] = new boolean[V];
    DFSUtil(v, visited);
  }
}