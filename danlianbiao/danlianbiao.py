#定义链表的节点
class Node(object):
    def __init__(self,elem):
        self.elem = elem
        self.next = None
#定义链表
class Single_Link_list(object):
    def __init__(self,node = None):
        self._head = node
    #判断链表是否为空
    def is_emmpty(self):
        return self._head == None
    #返回链表的长度
    #使用cur游标移动，从而实现链表的遍历
    def list_length(self):
        cur = self._head
        count = 0
        while cur != None:
            count += 1
            cur = cur.next
        return count
    #遍历整个链表
    def travelAllList(self):
        cur = self._head
        while cur != None:
            print(cur.elem,end=" ")
            cur = cur.next
        print(end = "\n")
    #向链表头部添加元素
    def add(self,item):
        node = Node(item)
        node.next = self._head
        self._head = node
    #向链表尾部添加元素
    def append(self,item):
        node = Node(item)
        if self.is_emmpty():
            self._head = node
        else:
            cur = self._head
            while cur.next != None:
                cur = cur.next
            cur.next = node
    #在链表的指定位置添加元素
    def insert(self,pos,item):
        if pos <= 0:
            self.add(item)
        elif pos > (self.list_length() - 1):
            self.append(item)
        else:
            pre = self._head
            count = 0
            while count < (pos - 1):
                count += 1
                pre = pre.next
            node = Node(item)
            node.next = pre.next
            pre.next = node
    #在链表中删除元素
    def remove(self,item):
        cur = self._head
        pre = None
        while cur != None:
            if cur.elem == item:
                if cur == self._head:
                    self._head = cur.next
                else:
                    pre.next = cur.next
                break
            else:
                pre = cur
                cur = cur.next
    #查找节点是否存在
    def search(self,item):
        cur = self._head
        while cur != None:
            if cur.elem ==item:
                return True
            else:
                cur = cur.next
        return False
if __name__ =="__main__":
    ll = Single_Link_list()
    print(ll.is_emmpty())
    print(ll.list_length())
    ll.append(1)
    print(ll.is_emmpty())
    print(ll.list_length())
    ll.append(2)
    ll.append(3)
    ll.append(4)
    ll.append(5)
    ll.travelAllList()
    ll.insert(-1,30)
    ll.travelAllList()
    ll.insert(2,40)
    ll.travelAllList()
    ll.insert(10,300)
    ll.travelAllList()
    ll.remove(30)
    ll.travelAllList()
    ll.remove(300)
    ll.travelAllList()



