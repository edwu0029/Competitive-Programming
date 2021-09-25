'''
Shifty Sum
Canadian Computing Competition: 2017 Stage 1, Junior #2
https://dmoj.ca/problem/ccc17j2
'''

N = int(input())
k = int(input())
ans = N
for i in range(k):
    N*=10
    ans+=N
print(ans)