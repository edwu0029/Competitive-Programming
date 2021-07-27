#Problem: https://dmoj.ca/problem/ccc12j2

d1 = int(input())
d2 = int(input())
d3 = int(input())
d4 = int(input())
if d1<d2<d3<d4:
    print("Fish Rising")
elif d1>d2>d3>d4:
    print("Fish Diving")
elif d1==d2==d3==d4:
    print("Fish At Constant Depth")
else:
    print("No Fish")