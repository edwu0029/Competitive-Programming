'''
Quadrant Selection
Canadian Computing Competition: 2017 Stage 1, Junior #1
https://dmoj.ca/problem/ccc17j1
'''

x = int(input())
y = int(input())
if x>0 and y>0:
    print(1)
elif x<0 and y>0:
    print(2)
elif x<0 and y<0:
    print(3)
elif x>0 and y<0:
    print(4)
