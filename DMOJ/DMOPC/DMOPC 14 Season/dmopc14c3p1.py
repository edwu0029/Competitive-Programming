'''
Not Enough Users!
DMOPC '14 Contest 3 P1
https://dmoj.ca/problem/dmopc14c3p1
'''

import sys
input = sys.stdin.readline

N = int(input())
K = int(input())
D = int(input())
ans = N
for i in range(D):
    ans*=K
print(ans)