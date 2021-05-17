#Problem: https://dmoj.ca/problem/ccc21j3

import sys
input = sys.stdin.readline

pre = ""
while True:
    op = input().rstrip("\n")
    if op=="99999":
        break
    dir = int(op[0])+int(op[1])
    ans = ""
    if dir%2==1:
        ans+="left"
        pre = "left"
    elif dir%2==0 and dir!=0:
        ans+="right"
        pre = "right"
    elif dir==0:
        ans+=pre
    ans+=" "+op[2:]
    print(ans)