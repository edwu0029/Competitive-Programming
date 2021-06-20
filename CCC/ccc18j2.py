#Problem: https://dmoj.ca/problem/ccc18j2

N = int(input())
yesterday = input()
today = input()
cnt = 0
for i in range(N):
    if yesterday[i]=='.' or today[i]=='.':
        continue
    else:
        cnt+=1
print(cnt)