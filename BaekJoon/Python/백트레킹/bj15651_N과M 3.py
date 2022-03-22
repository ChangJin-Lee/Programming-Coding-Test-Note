import sys
import itertools
N,M = map(int,sys.stdin.readline().rstrip().split())
numbers=[]
for i in range(N):
    numbers.append(i+1)
# n𝝿m 중복순열
permutations = list(itertools.product(numbers,repeat=M))
for permutation in permutations:
    print(' '.join(map(str,permutation)))