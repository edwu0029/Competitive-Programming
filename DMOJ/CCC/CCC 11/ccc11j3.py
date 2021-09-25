'''
Sumac Sequences
Canadian Computing Competition: 2011 Stage 1, Junior #3
https://dmoj.ca/problem/ccc11j3
'''

p1 = int(input())
p2 = int(input())
p = p1-p2
ans = 3
while p<=p2:
    p1 = p2
    p2 = p
    p = p1-p2
    ans+=1
print(ans)