#利用数组实现队列
class myQueue():
    def __init__(self):
        self.arr = []
        self.front = 0
        self.rear = 0
    #判断队列是否为空
    def is_empty(self):
        return self.front == self.rear
    #判断队列是否为满
    def is_full(self):
        return (self.rear + 1) % (self.rear - self.front) == self.front
    #返回队列的大小
    def size(self):
        return self.rear - self.front
    #返回队列首元素
    def getFront(self):
        if self.is_empty():
            return None
        else:
            return self.arr[self.front]
    #返回队列尾部元素
    def getBack(self):
        if self.is_empty():
            return None
        else:
            return self.arr[self.rear - 1]
    #删除队列头元素
    def deQueue(self):
        if self.rear > self.front:
            self.front += 1
        else:
            print("队列为空")
    #将新元素加入队列
    def enQueue(self,item):
        self.arr.append(item)
        self.rear += 1

if __name__ == "__main__":
    queue = myQueue()
    queue.enQueue(1)
    queue.enQueue(2)
    print("队列头部元素为："+str(queue.getFront()))
    print("队列尾部元素为："+str(queue.getBack()))
    print("队列大小为："+str(queue.size()))
    queue.deQueue()
    print("队列大小为："+ str(queue.size()))
    queue.enQueue(3)
    print("队列大小为"+ str(queue.size()))


