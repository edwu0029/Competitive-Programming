'''
Dog Treats
Canadian Computing Competition: 2020 Stage 1, Junior #1
https://dmoj.ca/problem/ccc20j1
'''

import sys
input = sys.stdin.readline

S = int(input())
M = int(input())
L = int(input())

score = S+(2*M)+(3*L)
if score>=10:
    print("happy")
else:
    print("sad")