#Problem: https://dmoj.ca/problem/ccc21j1

import sys
input = sys.stdin.readline

B = int(input())
P = (5*B)-400

print(P)
if P>100:
    print(-1)
elif P==100:
    print(0)
else:
    print(1)