#Problem: https://dmoj.ca/problem/ccc20j4

import sys
input = sys.stdin.readline

T = input()
S = input()

if len(T)<len(S):
    print("no")
    sys.exit()

for i in range(len(S)):
    S = S[1:]+S[0]
    if S in T:
        print("yes")
        sys.exit()
print("no")
