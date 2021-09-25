'''
Magic Squares
Canadian Computing Competition: 2016 Stage 1, Junior #2
https://dmoj.ca/problem/ccc16j2
'''

F = [[0 for i in range(4)] for i in range(4)]
sum = 0
for i in range(4):
    sum = 0
    F[i] = list(map(int, input().split(' ')))
    for j in range(4):
        sum+=F[i][j]

check = True
for i in range(4):
    tmpsum = 0
    for j in range(4):
        tmpsum+=F[i][j]
    if tmpsum!=sum:
        check = False
for i in range(4):
    tmpsum = 0
    for j in range(4):
        tmpsum+=F[j][i]
    if tmpsum!=sum:
        check = False
if check:
    print("magic")
else:
    print("not magic")
