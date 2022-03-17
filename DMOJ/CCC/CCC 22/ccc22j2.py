'''
Fergusonball Ratings
Canadian Computing Competition: 2022 Stage 1, Junior #2
https://dmoj.ca/problem/ccc22j2
'''

N = int(input())
cnt = 0
for i in range(N):
    goals = int(input())
    fouls = int(input())
    if 5*goals-3*fouls>40:
        cnt+=1
if cnt==N:
    print(str(cnt)+"+")
else:
    print(cnt)