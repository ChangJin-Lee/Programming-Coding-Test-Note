a = [1,5,8,10]

b = [5,7,10,1]

print(b.index(1))
print(b[b.index(a[0])])

i = b.index(a[0])

b[i], b[0] = b[0], b[i]

print(b)