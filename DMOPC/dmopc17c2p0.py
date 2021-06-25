#Problem: https://dmoj.ca/problem/dmopc17c2p0

x1, y1 = map(int, input().split(' '))
x2, y2 = map(int, input().split(' '))
xs, ys = map(int, input().split(' '))
D = int(input())

d1 = (x1-xs)**2 + (y1-ys)**2
d2 = (x2-xs)**2 + (y2-ys)**2
if(d1<=D**2 or d2<=D**2):
    print("Yes")
else:
    print("No")