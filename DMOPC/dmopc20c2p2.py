#Problem: https://dmoj.ca/problem/dmopc20c2p2

N, M = map(int, input().split(' '))
colours = list(map(int, input().split(' ')))
firstI = {}
lastI = {}
ans = 0
for i in range(len(colours)):
    if colours[i] not in firstI:
        firstI[colours[i]] = i
    lastI[colours[i]] = i
for _ in range(M):
    a, b = map(int, input().split(' '))
    if a in firstI and b in firstI:
        ans = max(ans, lastI[b]-firstI[a]+1)
print(ans)