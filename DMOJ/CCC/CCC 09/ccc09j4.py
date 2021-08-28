#Problem: https://dmoj.ca/problem/ccc09j4

w = int(input())
words = ["WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"]
l = 1
line = words[0]
num_words = 1
def fun(line):
    if num_words==1 and len(line)!=w:
        for j in range(w-len(line)):
            line+='.'
    elif len(line)!=w:
        while True:
            cnt = 0
            t = ""
            pre_space = False
            for j in range(len(line)):
                if len(line)+cnt<w and line[j]=='.' and not pre_space:
                    cnt+=1
                    t+='.'+line[j]
                    pre_space = True
                else:
                    t+=line[j]
                    pre_space = False
            line = t
            if len(line)==w:
                break
    return line
for i in range(1, 6):
    if len(line)+len(words[i])+1<=w:
        line+='.'+words[i]
        num_words+=1
    else:
        print(fun(line))
        line = words[i]
        num_words = 1
print(fun(line))