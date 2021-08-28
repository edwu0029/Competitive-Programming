#Problem: https://dmoj.ca/problem/ccc19j1

A = 3*int(input())+2*int(input())+int(input())
B = 3*int(input())+2*int(input())+int(input())
if A>B:
    print('A')
elif A==B:
    print('T')
else:
    print('B')
