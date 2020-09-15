#定义栈满压栈以及栈空弹栈的异常类。
class StackEmptyException(Exception):pass
class StackFullException(Exception):pass
#定义链表节点
class Node:
    def __init__(self,val = None,nxt = None):
        self.value = val
        self.next = nxt
    def __str__(self):
        return str(self.value)
#定义链表栈
class Stack:
    """
    Stack based on linked list:
        | item3 |
        |   |   |
        |   V   |
        | item2 |
        |   |   |
        |   V   |
        | item1 |
         -------
    """
    def __init__(self, max=0):
        self._top = None
        self._max = 0
        self.max = max
    #定义栈的容量
    def max(self):
        return self._max
    def max(self,item):
        item = int(item)
        if item < self.length:
            raise Exception("Raise stack failed")
        self._max = item
        if self._max < 0:
            self._max = 0
    #定义栈的init方法，当栈为空栈的时候，第一个元素作为栈顶，随后依次push元素，最后一个入栈的元素作为栈顶
    def init(self,iterable = ()): #初始化一个可迭代对象
        if not iterable:
            return
        self._top = Node(iterable[0])
        for i in iterable[1:]:
            node = self._top
            self._top = Node(i)
            self._top.next = node
    #栈的遍历
    def show(self):
        def _traversal(self):
            node = self._top
            while node and node.next:
                yield node
                node = node.next
            yield node

        print('\n'.join(map(lambda x: '|{:^7}|'.format(str(x)), _traversal(self))) + '\n ' + 7 * '-')
    #获取链表栈的长度
    def length(self):
        if self._top is None:
            return 0
        node = self._top
        i = 1
        while node.next:
            node = node.next
            i += 1
        return i
    #判断链表栈是否为空
    def is_empty(self):
        return self._top is None
    #判断链表栈是否为满
    def is_full(self):
        return bool(self._max and self.length == self._max)
    #向链表栈里添加元素
    def push(self,item):
        if not self._top:
            self._top = Node(item)
            return
        node = self._top
        self._top = Node(item)
        self._top.next = node
    #出栈
    def pop(self):
        if self.is_empty:
            raise StackEmptyException('Error: trying to pop element from an empty stack!')
        node = self._top
        self._top = self._top.next
        return node.value
    def top(self):
        return self._top.value if self._top else self._top

    def clear(self):
        while self._top:
            self.pop()
def test(stack):
    print('\nShow stack:')
    stack.show()

    print('\nInit linked list:')
    stack.init([1, 2, 3, 4, 5])
    stack.show()

    print('\nPush element to stack:')
    stack.push(6)
    stack.push(7)
    stack.push('like')
    stack.show()

    print('\nCheck top element:')
    print(stack.top())

    print('\nPop element from stack:')
    e = stack.pop()
    print('Element %s popped,' % e)
    stack.show()

    print('\nSet stack max size:')
    try:
        stack.max = 1
    except Exception as e:
        print(e)

    print('\nSet stack max size:')
    stack.max = 7
    print(stack.max)

    print('\nPush full stack:')
    try:
        stack.push(7)
    except StackFullException as e:
        print(e)

    print('\nClear stack:')
    stack.clear()
    stack.show()

    print('\nStack is empty:')
    print(stack.is_empty)

    print('\nPop empty stack:')
    try:
        stack.pop()
    except StackEmptyException as e:
        print(e)


if __name__ == '__main__':
    test(Stack())