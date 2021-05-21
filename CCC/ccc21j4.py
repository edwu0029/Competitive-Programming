#Problem: https://dmoj.ca/problem/ccc21j4

import sys
input = sys.stdin.readline

books = input().rstrip("\n")
L = 0
M = 0
S = 0
for i in books:
    if i=='L':
        L+=1
    elif i=='M':
        M+=1
    else:
        S+=1
LinL = 0
LinM = 0
LinS = 0
MinL = 0
MinM = 0
MinS = 0
SinL = 0
SinM = 0
SinS = 0
for i in range(len(books)):
    if i<L:
        if books[i]=='L':
            LinL+=1
        elif books[i]=='M':
            MinL+=1
        elif books[i]=='S':
            SinL+=1
    elif i<(M+L):
        if books[i]=='L':
            LinM+=1
        elif books[i]=='M':
            MinM+=1
        elif books[i]=='S':
            SinM+=1
    elif i<(M+L+S):
        if books[i]=='L':
            LinS+=1
        elif books[i]=='M':
            MinS+=1
        elif books[i]=='S':
            SinS+=1
ans = 10000000
#L and M
n = (L-LinL)+(M-MinM)-min(LinM, MinL)
ans = min(ans, n)

#L and S
n = (L-LinL)+(S-SinS)-min(LinS, SinL)
ans = min(ans, n)

#M and S
n = (M-MinM)+(S-SinS)-min(MinS, SinM)
ans = min(ans, n)

print(ans)