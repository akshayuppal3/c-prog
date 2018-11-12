# simple node for LinkList
class Node:
    def __init__(self,data,weight):
        self.data = data
        self.weight = weight
        self.next_node = None

    def get_data(self):
        return self.data

    def get_weight(self):
        return self.weight

    def set_next(self,new_next):
        self.next_node = new_next

    def get_next(self):
        return self.next_node

# Link list collection of nodes


class LinkList2:
    def __init__(self,data=None,weight= None):
        self.head = Node(data,weight)

    def is_empty(self):
        if self.head is None:
            return True
        else:
            return False

    def addbeg(self,data,weight = None):
        if self.head is None:
            self.head = Node(data,weight)

        else:
            New_node = Node(data,weight)
            New_node.next_node = self.head
            self.head = New_node

    def add_pos(self,data,pos,weight= None):
        if pos is 0:
            self.addbeg(data)
        else:
            head = self.head
            count = 0
            while head:
                if count is pos-1:
                    New_node = Node(data, weight)
                    if head.next_node is not None:
                        New_node.next_node = head.next_node
                    head.next_node = New_node
                    break
                head = head.get_next()
                count = count + 1
            if head is None:
                print("position exceeded the length of the list")

    # add at the end of the list
    def append(self,data,weight=None):
        if self.is_empty():
            print("list is empty")
        else:
            head = self.head
            while head.next_node:
                head = head.next_node
            New_node = Node(data,weight)
            New_node.next_node = None
            head.next_node = New_node

    def add_end(self,data,weight = None):
        if self.head is None:
            self.head = Node(data,weight)
        else:
            head = self.head
            while head.next_node:
                head = head.next_node
            head.next_node = Node(data, weight)

    def search(self,data):
        if self.head is None:
            return None
        else:
            temp = self.head
            count = 0
            while temp:
                if (data is temp.data):
                    return(count)
                count = count + 1
                temp = temp.get_next()

    def delete(self,data):
        if self.head is None:
            print("list is empty")
        elif self.head.get_data() is data:
            self.head = self.head.next_node
        else:
            head = self.head
            flag = False
            while head:
                if head.next_node.get_data() is data:
                    flag = True
                    break
                head = head.get_next()

            if flag is False:
                print("list is empty")
            else:
                if head.next_node.next_node is None:      # next -> next doesn't exist
                    head.next_node = None
                else:
                    head.next_node = head.next_node.next_node

    # @returns a list of nodes and weights
    def get_nodes(self):
        if self.head is None:
            return None
        else:
            nodes = dict()
            head = self.head
            while head:
                nodes[head.get_data()] = head.get_weight()
                head = head.next_node
            return nodes

    def display(self):
        if self.head is None:
            print("Empty list")
        else:
            head = self.head
            while head:
                print(head.get_data(),head.get_weight())
                head = head.next_node

if __name__ == '__main__':
    list1 = LinkList2(10,0)
    list1.add_end(12,1)
    list1.add_end(15,2)
    list1.add_end(20,3)
    list1.delete(10)
    list1.add_pos(13,1)
    list1.append(22,0)
    list1.display()
    Nodes = list1.get_nodes()
    print(Nodes)