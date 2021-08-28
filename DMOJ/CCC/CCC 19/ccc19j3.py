#Problem: https://dmoj.ca/problem/ccc19j3

N = int(input())
for _ in range(N):
    L = input()
    pre = L[0]
    cnt = 1
    ans = ''
    for i in range(1, len(L)):
        cur = L[i]
        if cur==pre:
            cnt+=1
        else:
            ans+=str(cnt)+' '+pre+' '
            pre = cur
            cnt = 1
    ans+=str(cnt)+' '+pre+' '
    print(ans)