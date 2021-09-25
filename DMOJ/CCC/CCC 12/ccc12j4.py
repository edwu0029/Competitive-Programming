'''
Big Bang Secrets
Canadian Computing Competition: 2012 Stage 1, Junior #4
https://dmoj.ca/problem/ccc12j4
'''

K = int(input())
msg = input()
ans = ""
for i in range(len(msg)):
    shift = 3*(i+1)+K
    cd = ord(msg[i])-shift
    #'Z' = 90, 'A' = 65
    c = chr(90-65+cd+1) if cd<65 else chr(cd)
    ans+=c
print(ans)