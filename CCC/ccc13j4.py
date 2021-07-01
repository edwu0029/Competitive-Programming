#Problem: https://dmoj.ca/problem/ccc13j4

T = int(input())
C = int(input())
chores = []
for i in range(C):
    x = int(input())
    chores.append(x)
chores.sort()
ans = 0
for i in range(C):
    if T-chores[i]>=0:
        T-=chores[i]
        ans+=1
print(ans)