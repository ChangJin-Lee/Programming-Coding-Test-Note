import sys
N,M,K=map(int,sys.stdin.readline().rstrip().split())

numberlist=[0]
for _ in range(N):
    numberlist.append(int(sys.stdin.readline().rstrip()))
tree=[0 for _ in range(4*N)]

def fill_tree(start,end,index):
    if start==end:
        tree[index]=numberlist[start]
        return tree[index]
    
    mid=(start+end)//2
    tree[index]=fill_tree(start,mid,2*index) + fill_tree(mid+1,end,2*index+1)
    return tree[index]


def return_sum(start,end,left,right,index):
    if end<left or start>right:
        return 0
    
    if start<=left and right<=end:
        return tree[index]
    
    mid=(left+right)//2
    return return_sum(start,end,left,mid,2*index) + return_sum(start,end,mid+1,right,2*index+1)


def change_tree(start,end,index,changeidx):
    if start==end:
        tree[index]=numberlist[start]
        return tree[index]
    
    mid=(start+end)//2
    if changeidx<= mid:
        tree[index]=change_tree(start,mid,2*index,changeidx) + tree[2*index+1]
    if changeidx > mid:
        tree[index]=tree[2*index] + change_tree(mid+1,end,2*index+1,changeidx)
    return tree[index]


fill_tree(1,N,1)

for _ in range(M+K):
    a,b,c=map(int,sys.stdin.readline().rstrip().split())
    if a==1:
        numberlist[b]=c
        change_tree(1,N,1,b)
    if a==2:
        print(return_sum(b,c,1,N,1))