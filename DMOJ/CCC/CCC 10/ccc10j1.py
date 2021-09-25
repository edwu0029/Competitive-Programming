'''
What is n, Daddy?
Canadian Computing Competition: 2010 Stage 1, Junior #1
https://dmoj.ca/problem/ccc10j1
'''

N = int(input())
ans = 0
for i in range(6):
    for j in range(i, 6):
        if i+j==N:
            ans+=1
print(ans)