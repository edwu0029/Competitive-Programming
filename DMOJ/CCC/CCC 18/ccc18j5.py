'''
Choose your own path
Canadian Computing Competition: 2018 Stage 1, Junior #5
https://dmoj.ca/problem/ccc18j5
'''

from collections import deque

N = int(input())
endpage = []
adj = [[] for i in range(N+1)]
for i in range(1, N+1):
    adj[i] = list(map(int, input().split(' ')))
    adj[i].pop(0)
    if len(adj[i])==0:
        endpage.append(i)

vis = [False for i in range(N+1)]
dis = [1000 for i in range(N+1)]
vis[1] = True
dis[1] = 1
q = deque([1])

cnt = 1
minpage = 1000
while q:
    cur = q.pop()
    if cur in endpage:
        minpage = min(minpage, dis[cur])
    for i in adj[cur]:
        if vis[i]==False:
            vis[i] = True
            dis[i] = dis[cur]+1
            cnt+=1
            q.appendleft(i)
if cnt==N:
    print("Y")
else:
    print("N")
print(minpage)