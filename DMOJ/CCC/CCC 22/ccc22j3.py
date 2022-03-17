'''
Harp Tuning
Canadian Computing Competition: 2022 Stage 1, Junior #3
https://dmoj.ca/problem/ccc22j3
'''

S = input()
steps = ""
for i in range(len(S)):
    steps+=S[i]
    if ord('0')<=ord(S[i])<=ord('9') and i!=len(S)-1 and ord('A')<=ord(S[i+1])<=ord('T'):
        steps+=" "
steps = steps.split(' ')
for step in steps:
    if '+' in step:
        t = step.index('+')
        print(step[:t]+" tighten "+step[t+1:])
    else:
        t = step.index('-')
        print(step[:t]+" loosen "+step[t+1:])