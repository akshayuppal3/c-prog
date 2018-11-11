import collections

# simple iterative bfs Application : topological sort


def dfs(graph, root):
    stack = collections.deque([root])
    visited_list = set()
    while stack:
        v = stack.pop()
        print(v)
        for neighbor in graph[v]:
            if neighbor not in visited_list:
                visited_list.add(neighbor)
                stack.append(neighbor)
# a recursive BFS


def dfs_r(graph,root):
    visited = set()
    visited.add(root)
    for edge in graph:
        if edge not in visited:
            print(edge)
            dfs_visit(graph, edge, visited)


def dfs_visit(graph, root, visited):
    for neighbor in graph[root]:
        if neighbor not in visited:
            visited.add(neighbor)
            print(neighbor)
            dfs_visit(graph, root, visited)

if __name__ == '__main__':
    graph1 = {0: [1, 2], 1: [2, 3], 2: [3, 4], 3: [4], 4: [5], 5: []}
    dfs_r(graph1,0)