'''
Art
Canadian Computing Competition: 2020 Stage 1, Junior #3
https://dmoj.ca/problem/ccc20j3
'''

import sys
input = sys.stdin.readline

N = int(input())
minX, maxX, minY, maxY = 200, -1, 200, -1
for i in range(N):
    x, y = map(int, input().split(','))
    minX = min(minX, x)
    maxX = max(maxX, x)
    minY = min(minY, y)
    maxY = max(maxY, y)
print(str(minX-1)+","+str(minY-1))
print(str(maxX+1)+","+str(maxY+1))