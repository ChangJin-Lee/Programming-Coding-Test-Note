import sys

def push(stack,val):
    stack.append(val)

def pop(stack):
    if not stack:
        return -1
    else:
        return stack.pop(-1)

def size(stack):
    if not stack:
        return 0
    else:
        return len(stack)

def empty(stack):
    if not stack:
        return 1
    else:
        return 0

def top(stack):
    if not stack:
        return -1
    else:
        return stack[-1]

N = int(sys.stdin.readline().rstrip())
mystack = []

for i in range(N):
    command = list(map(str,sys.stdin.readline().rstrip().split(" ")))
    if command[0] == "push":
        push(mystack,command[1])
    elif command[0] == "pop":
        print(pop(mystack))
    elif command[0] == "size":
        print(size(mystack))
    elif command[0] == "empty":
        print(empty(mystack))
    elif command[0] == "top":
        print(top(mystack))