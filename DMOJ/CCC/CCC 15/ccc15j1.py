#Problem: https://dmoj.ca/problem/ccc15j1

m = int(input())
d = int(input())
if m==2 and d==18:
    print("Special")
elif (m==2 and d<=18) or m<=2:
    print("Before")
else:
    print("After")