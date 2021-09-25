'''
Who Has Seen The Wind
Canadian Computing Competition: 2011 Stage 1, Junior #2
https://dmoj.ca/problem/ccc11j2
'''

h = int(input())
M = int(input())
def A(t):
    return -6*t**4+h*t**3+2*t**2+t
T = -1
for i in range(1, M+1):
    if A(i)<=0:
        T = i
        break
if T==-1:
    print("The balloon does not touch ground in the given time.")
else:
    print("The balloon first touches ground at hour:")
    print(T)