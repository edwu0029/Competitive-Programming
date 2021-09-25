'''
High Tide, Low Tide
Canadian Computing Competition: 2017 Stage 1, Senior #2
https://dmoj.ca/problem/ccc17s2
'''

N = int(input())
F = list(map(int, input().split(' ')))
F.sort()
lows = []
highs = []
if N%2==0:
    lows = F[:N//2]
    highs = F[N//2:]
else:
    lows = F[:(N//2)+1]
    highs = F[(N//2)+1:]
lows.reverse()
for i in range(N//2):
    print(lows[i], end=" ")
    print(highs[i], end=" ")
if N%2==1:
    print(lows[len(lows)-1])
