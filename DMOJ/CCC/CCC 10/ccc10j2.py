#Problem: https://dmoj.ca/problem/ccc10j2

a = int(input())
b = int(input())
c = int(input())
d = int(input())
s = int(input())
N, B = 0, 0
for i in range(0, s):
    if i%(a+b)<a:
        N+=1
    else:
        N-=1
    if i%(c+d)<c:
        B+=1
    else:
        B-=1
if N>B:
    print("Nikky")
elif N<B:
    print("Byron")
else:
    print("Tied")
