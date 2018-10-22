"""
Breadth First Search

Graph(N) is a directed graph that has node 0, 1, 2, ..., N-1.
A function BFS(G, S) traverses graph G with start node S.
"""
class Node:
    def __init__ (self):
        self.edges = []

class Graph:
    def __init__ (self, N):
        self.nodes = [Node() for i in range(N)]
    
    def add_edge (self, source, destination):
        self.nodes[source].edges.append(destination)

def BFS(graph, start_index):
    stack = [start_index]
    visited = []
    while len(stack) > 0:
        current = stack.pop(0)
        if current in visited:
            continue
        visited.append(current)
        print('Visit node ' + str(current))
        for dest in graph.nodes[current].edges:
            stack.append(dest)

graph = Graph(5)
graph.add_edge(0, 1)
graph.add_edge(1, 2)
graph.add_edge(3, 4)
graph.add_edge(1, 3)
BFS(graph, 0)
