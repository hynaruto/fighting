class Sequence_Table():
    def __init__(self):
        self.date = [None] * 10000
        self.length = 0
    # 判断顺序表是否为满
    def isFull(self):
        if self.length > 1000:
            print("顺序表已满，无法添加元素")
            return 1
        else:
            return 0
    # 按照索引查找
    def selectByIndex(self,index):
        if index >= 0 and index <= self.length -1:
            return self.date[index]
        else:
            print("输入的下标不对，请重新输入\n")
    # 顺序表查找元素的下标
    def selectBy_Num(self,ele):
        isContain = 0
        for i  in range(0,self.length):
            if self.date[i] == ele:
                isContain = 1
                print("查找的下标元素是：%d\n"%i)
            if isContain == 0:
                print("查找的元素不存在")
    # 向顺序表里添加元素
    def add_Num(self,num):
            self.date[self.length] = num
            self.length += 1
    # 打印
    def printALLNum(self):
        for i in range(self.length):
            print("a[%s] = %s"%(i,self.date[i]),end="")
    # 按照下标插入数据
    def insertNumByIndex(self,num,index):
        if index < 0 and index > self.length:
            return 0
        self.length+=1
    # 从顺序表尾部插入元素
        for i in range(self.length - 1,index,-1):
            temp = self.date[i]
            self.date[i] = self.date[i - 1]
            self.date[i - 1] = temp
        self.date[index] = num
        return 1
    # 按照下标删除元素
    def deleteNumByindex(self,index):
        if self.length  <= 0:
            print("该顺序表内没有元素，不用删除")
        # 从index位置到最后将元素后移，保序的元素删除
        for i in range(index,self.length - 1):
            temp = self.date[i]
            self.date[i] = self.date[i + 1]
            self.date[i + 1] = temp
        self.date[self.length - 1] = 0
        self.length -= 1


def main():
    # 创建顺序表
    seq_t = Sequence_Table()
    #插入元素
    seq_t.add_Num(1)
    seq_t.add_Num(2)
    seq_t.add_Num(3)
    seq_t.add_Num(4)
    # 打印元素
    seq_t.printALLNum()
    # 按照索引查找
    num = seq_t.selectByIndex(3)
    print("查找的数据是：%d" %num)
    # 按照索引插入数据
    seq_t.insertNumByIndex(2,1)
    seq_t.printALLNum()
    # 按照数字查找下标
    seq_t.selectBy_Num(3)
    # 删除数据
    seq_t.deleteNumByindex(1)
    seq_t.printALLNum()


if __name__ == "__main__":
    main()










