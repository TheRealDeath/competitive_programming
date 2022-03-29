from collections import defaultdict
class Graph:
	def __init__(self):
		self.graph = defaultdict(list)
	def addEdge(self, u, v):
		self.graph[u].append(v)
	def DFSUtil(self, v, visited,myList):
		visited.add(v)
		myList.append(v)
		for neighbour in self.graph[v]:
			if neighbour not in visited:
				self.DFSUtil(neighbour, visited)
		return myList
	def DFS(self, v):
		visited = set()
		return self.DFSUtil(v, visited,[])