'''
Time to Decompress
Canadian Computing Competition: 2019 Stage 1, Junior #2
https://dmoj.ca/problem/ccc19j2
'''

T = int(input())
for _ in range(T):
    x, c = input().split(' ')
    x = int(x)
    print(x*c)
