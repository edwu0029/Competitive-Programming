'''
Telemarketer or not?
Canadian Computing Competition: 2018 Stage 1, Junior #1
https://dmoj.ca/problem/ccc18j1
'''

a = int(input())
b = int(input())
c = int(input())
d = int(input())

if (a==8 or a==9) and b==c and (d==8 or d==9):
    print("ignore")
else:
    print("answer")