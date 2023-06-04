import sys

dance = []

for k in range(5):
    t = str(sys.stdin.readline().rstrip())
    scene = [y for y in t]
    dance.append(scene)

result = []
lens = len(dance[0])
for i in range(lens):
    s = ""
    for j in range(5):
        s+=dance[j][i]
    if s == "owln.":
        result.append(".omln")
    elif s == ".omln":
        result.append("owln.")
    else:
        result.append("..oLn")
for i in range(5):
    for j in range(lens):
        print(result[j][i],end="")
    print("")