# implementation for simple directed graph

# Properties 1: to add edges in the graph
#            2: display adjacent nodes for an edge
#            3: get adjacent nodes in the graph

from linklist2 import LinkList2

class Graph_weighted:
    def __init__(self):
        self.graph = dict()

    # @return bool true ro false
    def is_empty(self):
        if not self.graph:
            return True
        else:
            return False

    # @returns None
    # appends the edges to the link list
    def add_edge(self,node1,node2,weight=None):
        if (node1 not in self.graph):
            self.graph[node1] = LinkList2(node2,weight)
        else:
            head = self.graph[node1]
            head.append(node2,weight)

    # returns None
    # prints the list of all the elements in the graph
    def display_adj(self,node1):
        if (node1 not in self.graph):
            print(node1,"doesnt exists in the graph")
        else:
            head = self.graph[node1]
            head.display()

    # @returns List of all elements in the list
    def get_adj(self,node1):
        if node1 not in self.graph:
            print(node1,"doesnt exists in the graph")
            return None
        else:
            head = self.graph[node1]
            nodes = head.get_nodes()
            return nodes

    # return a list of all vertices of graph
    def get_vertices(self):
        if self.is_empty():
            print("graph is empty")
        else:
            vertices = list()
            for key in self.graph:
                vertices.append(key)
            return vertices

    # @returns a custom graph
    def get_custom_graph(self):
        g = Graph_weighted()
        g.add_edge(1, 2, 3)
        g.add_edge(1, 2, 7)
        g.add_edge(1, 7, 4)
        g.add_edge(1, 4, 90)
        g.add_edge(1, 5, 77)
        g.add_edge(2, 3, 66)
        g.add_edge(2, 5, 44)
        g.add_edge(3, 2, 1)
        g.add_edge(3, 7, 3)
        g.add_edge(3, 4, 6)
        g.add_edge(3, 6, 1)
        g.add_edge(4, 3, 1)
        g.add_edge(4, 1, 8)
        g.add_edge(4, 7, 6)
        g.add_edge(4, 5, 3)
        g.add_edge(5, 4, 2)
        g.add_edge(5, 2, 1)
        g.add_edge(5, 1, 6)
        g.add_edge(5, 6, 6)
        g.add_edge(6, 5, 3)
        g.add_edge(6, 3, 88)
        g.add_edge(6, 7, 99)
        g.add_edge(7, 1, 65)
        g.add_edge(7, 3, 12)
        g.add_edge(7, 4, 12)
        g.add_edge(7, 6, 10)
        return g

if __name__ == '__main__':
    g = Graph_weighted()
    g = g.get_custom_graph()

    vertices = g.get_adj(7)
    print(vertices)