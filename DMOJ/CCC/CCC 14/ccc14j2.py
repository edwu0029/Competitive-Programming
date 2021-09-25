'''
Vote Count
Canadian Computing Competition: 2014 Stage 1, Junior #2
https://dmoj.ca/problem/ccc14j2
'''

V = int(input())
votes = input()
if votes.count('A')>votes.count('B'):
    print("A")
elif votes.count('A')<votes.count('B'):
    print("B")
else:
    print("Tie")