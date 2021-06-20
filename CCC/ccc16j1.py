#Problem: https://dmoj.ca/problem/ccc16j1

win = 0
for i in range(6):
    x = input()
    if x=='W':
        win+=1
if win==5 or win==6:
    print(1)
elif win==3 or win==4:
    print(2)
elif win==2 or win==3:
    print(3)
else:
    print(-1)
