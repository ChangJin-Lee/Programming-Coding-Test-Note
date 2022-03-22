import sys
import itertools
N,M = map(int,sys.stdin.readline().rstrip().split())
numbers=[]
for i in range(N):
    numbers.append(i+1)
# nCm 조합
permutations = list(itertools.combinations(numbers,M))
for permutation in permutations:
    print(' '.join(map(str,permutation)))