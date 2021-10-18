'''
Epidemiology
Canadian Computing Competition: 2020 Stage 1, Junior #2
https://dmoj.ca/problem/ccc20j2
'''

import sys
input = sys.stdin.readline

P = int(input())
N = int(input())
R = int(input())

if N>P:
    print(0)
else:
    pre = N
    day = 0
    while True:
        day+=1
        N+=(R*pre)
        pre*=R
        if P<N:
            print(day)
            break