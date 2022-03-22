import sys

Ca, Ba, Pa = map(int, sys.stdin.readline().rstrip().split())
Cr, Br, Pr = map(int, sys.stdin.readline().rstrip().split())
passengers = 0
if Cr > Ca:
    passengers += Cr - Ca
if Br > Ba:
    passengers += Br - Ba
if Pr > Pa:
    passengers += Pr - Pa
print(passengers)
