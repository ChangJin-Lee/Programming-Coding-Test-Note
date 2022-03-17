import sys

def push(stack, val):
    if val != 0:
        stack.append(val)
    else:
        stack.pop(-1)

def print_stack(stack):
    print(sum(stack))

k = int(sys.stdin.readline().rstrip())
stack = []
for i in range(k):
    n = int(sys.stdin.readline().rstrip())
    push(stack, n)
print_stack(stack)