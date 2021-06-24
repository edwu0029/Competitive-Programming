#Problem: https://dmoj.ca/problem/ccc15j3

alpha = "abcdefghijklmnopqrstuvwxyz"
vowels = "aeiou"
consonats = "bcdfghjklmnpqrstvwxyzz"
f1 = [0 for i in range(26)]
f2 = [0 for i in range(26)]
for i in range(26):
    if alpha[i] in vowels:
        continue
    #Closest vowel
    if alpha[i] in "bc":
        f1[i] = 'a'
    elif alpha[i] in "dfg":
        f1[i] = 'e'
    elif alpha[i] in "hjkl":
        f1[i] = 'i'
    elif alpha[i] in "mnpqr":
        f1[i] = 'o'
    else:
        f1[i] = 'u'
    
    #Closest consonant
    f2[i] = alpha[i]
    for j in range(i+1, 26):
        if alpha[j] in vowels:
            continue
        else:
            f2[i] = alpha[j]
            break
N = input()
ans = ""
for i in N:
    ans+=i
    if i in consonats:
        ans+=f1[ord(i)-ord('a')]
        ans+=f2[ord(i)-ord('a')]
print(ans)