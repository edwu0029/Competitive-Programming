'''
Ragaman
Canadian Computing Competition: 2016 Stage 1, Senior #1
https://dmoj.ca/problem/ccc16s1
'''

A = input()
B = input()
Afreq = [0 for i in range(26)]
Bfreq = [0 for i in range(26)]
asterik = 0
ans = True
for i in A:
    Afreq[ord(i)-97]+=1
for i in B:
    if i!='*':
        Bfreq[ord(i)-97]+=1
for i in range(26):
    if Afreq[i]<Bfreq[i]:
        ans = False
if ans:
    print("A")
else:
    print("N")
