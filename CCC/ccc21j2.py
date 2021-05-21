#Problem: https://dmoj.ca/problem/ccc21j2

import sys
input = sys.stdin.readline

N = int(input())
ans1 = ""
ans2 = 0

for i in range(N):
    na = input()
    bid = int(input())
    if bid>ans2:
        ans1 = na
        ans2 = bid
print(ans1)

