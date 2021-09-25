'''
Voronoi Villages
Canadian Computing Competition: 2018 Stage 1, Senior #1
https://dmoj.ca/problem/ccc18s1
'''

N = int(input())
F = [0 for i in range(N)]
sz = [0 for i in range(N)]
for i in range(N):
    x = int(input())
    F[i] = x
F.sort()
for i in range(1, N):
    diff = (F[i]-F[i-1])/2.0
    sz[i-1]+=diff
    sz[i]+=diff
ans = sz[1]
for i in range(1, N-1):
    ans = min(ans, sz[i])
print(ans)
