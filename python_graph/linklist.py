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

# Link list collection of nodes


class LinkList:
    def __init__(self,data=None):
        self.head = Node(data)

    def is_empty(self):
        if self.head is None:
            return True
        else:
            return False

    def addbeg(self,data):
        if self.head is None:
            self.head = Node(data)

        else:
            New_node = Node(data)
            New_node.next_node = self.head
            self.head = New_node

    def add_pos(self,data,pos):
        if pos is 0:
            self.addbeg(data)
        else:
            head = self.head
            count = 0
            while head:
                if count is pos-1:
                    New_node = Node(data)
                    if head.next_node is not None:
                        New_node.next_node = head.next_node
                    head.next_node = New_node
                    break
                head = head.get_next()
                count = count + 1
            if head is None:
                print("position exceeded the length of the list")

    # add at the end of the list
    def append(self,data):
        if self.is_empty():
            print("list is empty")
        else:
            head = self.head
            while head.next_node:
                head = head.next_node
            New_node = Node(data)
            New_node.next_node = None
            head.next_node = New_node

    def add_end(self,data):
        if self.head is None:
            self.head = Node(data)
        else:
            head = self.head
            while head.next_node:
                head = head.next_node
            head.next_node = Node(data)

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

    def display(self):
        if self.head is None:
            print("Empty list")
        else:
            head = self.head
            while head:
                print(head.get_data())
                head = head.next_node


if __name__ == '__main__':
    list1 = LinkList(10)
    list1.add_end(12)
    list1.add_end(15)
    list1.add_end(20)
    list1.delete(10)
    list1.add_pos(13,1)
    list1.append(22)
    list1.display()