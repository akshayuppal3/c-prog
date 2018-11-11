
# simple node for LinkList
class Node:
    def __init__(self,data):
        self.data = data
        self.next_node = None

    def get_data(self):
        return self.data

    def set_next(self,new_next):
        self.next_node = new_next

    def get_next(self):
        return self.next_node

if __name__ == '__main__':
    node = Node(0)
    node.get_data()
    node1 = Node(1)

    node2 = Node(2)
    node.set_next(node1)
    node1.set_next(node2)

    while node:
        a = node.get_data()
        print(a)
        node = node.get_next()

