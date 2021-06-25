#Problem: https://dmoj.ca/problem/dmopc15c6p3

N, M, K = map(int, input().split(' '))
rows = [0 for i in range(N+1)]
for i in range(M):
    a, b = map(int, input().split(' '))
    rows[a]-=1
    if b<N:
        rows[b+1]+=1
for i in range(1, N+1):
    rows[i]+=rows[i-1]
pre = [0 for i in range(N+1)]
for i in range(1, N+1):
    pre[i] = rows[i]+M
for i in range(1, N+1):
    pre[i]+=pre[i-1]

l = 1
r = 1
ans = 6000000
while l<=r and r<=N:
    if pre[r]-pre[l-1]>=K:
        ans = min(ans, r-l+1)
        l+=1
    else:
        r+=1
if ans==6000000:
    print("-1")
elif K==0:
    print("0")
else:
    print(ans)