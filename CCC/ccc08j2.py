#Problem: https://dmoj.ca/problem/ccc08j2

ls = ["A", "B", "C", "D", "E"]
def push(num):
    if num==1:
        t = ls[0]
        ls.pop(0)
        ls.append(t)
    elif num==2:
        t = ls[4]
        ls.pop(4)
        ls.insert(0, t)
    elif num==3:
        ls[0], ls[1] = ls[1], ls[0]
while True:
    b = int(input())
    n = int(input())
    if b==4:
        break
    else:
        for i in range(n):
            push(b)
for i in ls:
    print(i, end=" ")