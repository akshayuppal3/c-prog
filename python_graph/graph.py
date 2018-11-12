# implementation for simple directed graph

# Properties 1: to add edges in the graph
#            2: display adjacent nodes for an edge
#            3: get adjacent nodes in the graph

from linklist import LinkList

class Graph:
    def __init__(self):
        self.graph = dict()

    # @returns None
    # appends the edges to the link list
    def add_edge(self,node1,node2):
        if (node1 not in self.graph):
            self.graph[node1] = LinkList(node2)
        else:
            head = self.graph[node1]
            head.append(node2)

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

if __name__ == '__main__':
    g = Graph()
    g.add_edge(1,2)
    g.add_edge(1, 2)
    g.add_edge(1, 7)
    g.add_edge(1, 4)
    g.add_edge(1, 5)
    g.add_edge(2, 3)
    g.add_edge(2, 5)
    g.add_edge(3, 2)
    g.add_edge(3, 7)
    g.add_edge(3, 4)
    g.add_edge(3, 6)
    g.add_edge(4, 3)
    g.add_edge(4, 1)
    g.add_edge(4, 7)
    g.add_edge(4, 5)
    g.add_edge(5, 4)
    g.add_edge(5, 2)
    g.add_edge(5, 1)
    g.add_edge(5, 6)
    g.add_edge(6, 5)
    g.add_edge(6, 3)
    g.add_edge(6, 7)
    g.add_edge(7, 1)
    g.add_edge(7, 3)
    g.add_edge(7, 4)
    g.add_edge(7, 6)

    a = g.get_adj(3)
    print(a)