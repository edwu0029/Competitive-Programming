'''
Rotating letters
Canadian Computing Competition: 2013 Stage 1, Junior #2
https://dmoj.ca/problem/ccc13j2
'''

rot = "IOSHZXN"
n = input()
ans = True
for i in n:
    if i not in rot:
        ans = False
if ans:
    print("YES")
else:
    print("NO")