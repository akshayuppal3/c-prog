# implementation of prims algo for MST
import math

from graph_weighted import Graph_weighted

def prims(graph,start_node):
    vertice_info = dict()     # Represent each vertice : ( value , parent )
    vertices = graph.get_vertices()
    for vertex in vertices:
        vertice_info[vertex] = (math.inf,None)
    vertice_info[start_node] = (0, None)
    while vertice_info:
        sort = sorted(vertice_info.items(), key=lambda x: x[1])
        min_vertex = sort[0][0]    #signifies the vertex
        weight_parent = vertice_info.pop(min_vertex)
        print(min_vertex, weight_parent)
        for vertex,weight in graph.get_adj(min_vertex).items():
            if vertex in vertice_info:
                vertex_weight= vertice_info[vertex][0]
                if weight < vertex_weight:
                    vertice_info[vertex] = (weight,min_vertex)

if __name__ == '__main__':
    g = Graph_weighted()
    g = g.get_custom_graph()
    info = prims(g,1)

    print("BOO")