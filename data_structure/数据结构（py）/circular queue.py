#定义队列
class SqQueue(object):
    def __init__(self,maxsize):
        self.front = 0
        self.rear = 0
        self.maxsize = maxsize
        self.queue = [None] * maxsize
    #返回当前队列长度
    def QueueLength(self):
        return (self.rear - self.front + self.maxsize) % self.maxsize
    #在队尾插入元素;在队列未满的情况下
    def EnQueue(self,item):
        if (self.rear + 1) % self.maxsize == self.front:
            print("队列已满")
        else:
            self.queue[self.rear] = item
            self.rear = (self.rear + 1) % self.maxsize
    #在队列不为空的条件下，删除队头元素
    def DeQueue(self):
        if self.rear == self.front:
            print("队列为空")
        else:
            data = self.queue[self.front]
            self.queue[self.front] = None
            self.front = (self.front + 1) % self.maxsize
            return data
    #输出队列元素
    def ShowQueue(self):
        for i in range(self.maxsize):
            print(self.queue[i],end = ",")
        print(" ")

if __name__ == "__main__":
    q = SqQueue(15)
    for i in range(10):
        q.EnQueue(i)
    q.ShowQueue()


    for i in range(5):
        q.DeQueue()
    q.ShowQueue()

    for i in range(8):
        q.EnQueue(i)
    q.ShowQueue()


