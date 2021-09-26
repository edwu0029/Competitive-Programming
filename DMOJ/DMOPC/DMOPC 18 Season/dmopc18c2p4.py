'''
Damage Output
DMOPC '18 Contest 2 P4
https://dmoj.ca/problem/dmopc18c2p4
'''

import sys
input = sys.stdin.readline

N, M = map(int, input().split(' '))
pre = list(map(int, input().split(' ')))
for i in range(1, N):
    pre[i]+=pre[i-1]
l, r, ans = 0, 0, 1000000
while l<=r and r<N:
    diff = pre[r]
    if l>0:
        diff-=pre[l-1]
    if diff>=M:
        ans = min(ans, r-l+1)
        l+=1
    else:
        r+=1
if ans==1000000:
    print("-1")
else:
    print(ans)