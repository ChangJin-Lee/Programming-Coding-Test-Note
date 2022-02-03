import sys

n = int(sys.stdin.readline().rstrip())
queue = [i+1 for i in range(n)]
dequeue = []
if n == 1:
    print(n)
else:
    while True:
        dequeue.append(queue.pop(0))
        if len(queue) == 1 : break
        queue.append(queue.pop(0))
        if len(queue) == 1 : break

    dequeue.append(queue[0])
    for num in dequeue:
        print(num, end=" ")