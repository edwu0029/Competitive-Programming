#Problem: https://dmoj.ca/problem/ccc21s1

import sys
input = sys.stdin.readline

N = int(input())
h = list(map(int, input().split(' ')))
w = list(map(int, input().split(' ')))

ans = 0
for i in range(N):
    ans+=w[i]*(h[i]+h[i+1])
ans/=2
print(ans)
