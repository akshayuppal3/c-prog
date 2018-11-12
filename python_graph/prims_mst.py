import math

from graph import Graph

def prims(graph,start_node):
    vertice_info = dict()     # Represent each vertice with value and parent
    vertices = graph.get_vertices()
    for vertex in vertices:
        vertice_info[vertex] = (math.inf,None)
    vertice_info[start_node] = (0, None)
    while vertice_info:
        sort = sorted(vertice_info.items(), key=lambda x: x[1])
        min_vertex = sort[0][0]    #signifies the vertex
        vertice_info.pop(min_vertex)
        for adj,weight in graph.get_adj(min_vertex):
        

    return vertice_info


if __name__ == '__main__':
    g = Graph()
    g = g.get_custom_graph()
    info = prims(g,1)
    print(info)
    a = sorted(info.items(), key=lambda x: x[1])
    print(a[0][0])