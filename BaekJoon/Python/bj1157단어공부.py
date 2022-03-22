import sys
def num_frequency(a):
    max, str, isequal= -1 , "", 0
    for i in range(97,123):
        if chr(i) in a or chr(i-32) in a:
            sum_value = a.count(chr(i)) + a.count(chr(i - 32))
            if sum_value > max: max = sum_value; str = chr(i-32); isequal = 0
            elif sum_value == max: isequal = 1
            # isequal 없이 return "?" 를 elif 뒤에 적었는데 오류가 나왔음
            # 왜? ABCDEFGHIJKLMNNNNNNNNNNNNNNNNN 와 같은 케이스에서
            # 마지막까지 다 읽고 나서야 ?인지 확인해야 하기 때문임.
    if isequal == 0: return str
    else: return "?"

string = sys.stdin.readline().rstrip()
print(num_frequency(string))