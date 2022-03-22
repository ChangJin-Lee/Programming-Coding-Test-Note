import sys
import itertools
N,M = map(int,sys.stdin.readline().rstrip().split())
numbers=[]
for i in range(N):
    numbers.append(i+1)
# nPm 순열
permutations = list(itertools.permutations(numbers,M))
for permutation in permutations:
    print(' '.join(map(str,permutation)))