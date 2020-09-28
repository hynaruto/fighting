#定义链表结点
class LNode():
    def __init__(self):
        self.data = None
        self.next = None
    #定义链表队列
class MyQueue():
    def __init__(self):
        self.front = None
        self.rear = None
    #判断链表队列是否为空
    def is_Empty(self):
        if self.front == None:
            return True
        else:
            return False
    #获取链表队列中元素个数
    def size(self):
        size = 0
        f = self.front
        while f != None:
            f = f.next
            size += 1
        return size
    #向链表队列加入元素
    def enQueue(self,item):
        f = LNode
        f.data = item
        f.next = None
        if self.front == None:
            self.front = self.rear = f
        else:
            self.rear.next = f
            self.rear = f
        #删除队首元素
    def getFront(self):
        if self.front == None:
            print("队列为空")
            return None
        else:
            return self.front.data
    #获得队列队尾元素
    def getBack(self):
        if self.rear == None:
            print("队列已经为空")
            return None
        else:
            return self.rear.data


if __name__ == "__main__":
    queue = MyQueue()
    queue.enQueue(1)
    queue.enQueue(2)
    print("队列头元素为："+str(queue.getFront()))
    print("队列尾元素为："+str(queue.getBack()))
    print("队列大小为："+str(queue.size()))






