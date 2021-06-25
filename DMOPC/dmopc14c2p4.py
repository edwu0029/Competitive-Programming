#Problem: https://dmoj.ca/problem/dmopc14c2p4

import sys
input = sys.stdin.readline

N = int(input())
sum = [0 for i in range(N+1)]
for i in range(N):
    sum[i] = int(input())
    if i>0:
        sum[i]+=sum[i-1]
Q = int(input())
for i in range(Q):
    a, b = map(int, input().split(' '))
    if a==0:
        print(sum[b])
    else:
        print(sum[b]-sum[a-1])