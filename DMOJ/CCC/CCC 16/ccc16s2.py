#Problem: https://dmoj.ca/problem/ccc16s2

q = int(input())
N = int(input())
d = list(map(int, input().split(' ')))
p = list(map(int, input().split(' ')))
d.sort()
p.sort()
ans = 0
if q==1:
    for i in range(N):
        ans+=max(d[i], p[i])
else:
    for i in range(N):
        ans+=max(d[i], p[N-i-1])
print(ans)
