'''
Hidden Palindrome
Canadian Computing Competition: 2016 Stage 1, Junior #3
https://dmoj.ca/problem/ccc16j3
'''

def check(A):
    for i in range(len(A)//2):
        if A[i]!=A[len(A)-i-1]:
            return False
    return True

S = input()
N = len(S)
ans = 1
for i in range(2, N+1):
    for j in range(i, N+1):
        if check(S[j-i:j]):
            ans = max(ans, i)
print(ans)
