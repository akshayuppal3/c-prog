import collections

def bfs(graph,root):
	queue = collections.deque([root])
	visited_list = set()
	while queue:
		new = queue.popleft()
		print(new)
		for neighbor in graph[new]:
			if neighbor not in visited_list:
				visited_list.add(neighbor)
				queue.append(neighbor)

if __name__ =="__main__":
	graph = {0:[1,2],1:[2,3],2:[3,4],3:[4],4:[5],5:[]}
	bfs(graph,0)