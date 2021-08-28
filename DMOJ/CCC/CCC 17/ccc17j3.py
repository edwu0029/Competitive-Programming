#Problem: https://dmoj.ca/problem/ccc17j3

a, b = map(int, input().split(' '))
c, d = map(int, input().split(' '))
t = int(input())
t-=(abs(a-c)+abs(b-d))
if t<0:
    print('N')
elif t%2==0:
    print('Y')
else:
    print('N')