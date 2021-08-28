#Problem: https://dmoj.ca/problem/ccc11j5

N = int(input())
adj = [[0 for i in range(7)] for i in range(7)]
ans = [1 for i in range(7)]
for i in range(1, N):
    pa = int(input())
    adj[i][pa] = 1
    adj[pa][i] = 1

def dfs(pre, cur):
    tot = 1
    for i in range(1, N+1):
        if i==pre or adj[cur][i]==0:
            continue
        dfs(cur, i)
        tot*=(1+ans[i])
    ans[cur] = tot
dfs(-1, N)
print(ans[N])