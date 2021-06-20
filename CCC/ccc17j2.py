#Problem: https://dmoj.ca/problem/ccc17j2

N = int(input())
k = int(input())
ans = N
for i in range(k):
    N*=10
    ans+=N
print(ans)