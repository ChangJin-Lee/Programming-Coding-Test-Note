#bj2869_달팽이
import sys,math

A, B, V = map(int,sys.stdin.readline().rstrip().split())

lastday = math.ceil((V-A)/(A-B))
print(lastday+1)