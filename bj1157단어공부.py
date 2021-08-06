import sys
def num_frequency(a):
    max, str, isequal= -1 , "", 0
    for i in range(97,123):
        if chr(i) in a or chr(i-32) in a:
            sum_value = a.count(chr(i)) + a.count(chr(i - 32))
            if sum_value > max: max = sum_value; str = chr(i-32); isequal = 0
            elif sum_value == max: isequal = 1
    if isequal == 0: return str
    else: return "?"

string = sys.stdin.readline().rstrip()
print(num_frequency(string))