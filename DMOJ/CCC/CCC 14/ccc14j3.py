'''
Double Dice
Canadian Computing Competition: 2014 Stage 1, Junior #3
https://dmoj.ca/problem/ccc14j3
'''

N = int(input())
A, D = 100, 100
for i in range(N):
    ar, ad = map(int, input().split(' '))
    if ar>ad:
        D-=ar
    elif ar<ad:
        A-=ad
print(A)
print(D)