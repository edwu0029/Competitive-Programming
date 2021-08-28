#Problem: https://dmoj.ca/problem/ccc14j1

a1 = int(input())
a2 = int(input())
a3 = int(input())

if a1+a2+a3!=180:
    print("Error")
elif a1!=a2 and a2!=a3 and a1!=a3:
    print("Scalene")
elif a1==a2 and a2==a3:
    print("Equilateral")
else:
    print("Isosceles")