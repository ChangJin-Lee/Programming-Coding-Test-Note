import sys
croatia = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
s = sys.stdin.readline().rstrip()
for i in croatia:
    s = s.replace(i,'_')
    print(s)
print(len(s))