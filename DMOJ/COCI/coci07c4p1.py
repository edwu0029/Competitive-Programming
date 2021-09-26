'''
Vauvau
COCI '07 Contest 4 #1
https://dmoj.ca/problem/coci07c4p1
'''

def ans(a, b):
    if(a+b==2):
        print("both")
    elif(a+b==1):
        print("one")
    else:
        print("none")
A, B, C, D = map(int, input().split(' '))
P, M, G = map(int, input().split(' '))

d1 = (P-1)%(A+B) < A
d2 = (P-1)%(C+D) < C
ans(d1, d2)

d1 = (M-1)%(A+B) < A
d2 = (M-1)%(C+D) < C
ans(d1, d2)

d1 = (G-1)%(A+B) < A
d2 = (G-1)%(C+D) < C
ans(d1, d2)
