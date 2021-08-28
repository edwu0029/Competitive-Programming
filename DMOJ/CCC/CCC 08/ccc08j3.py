#Problem: https://dmoj.ca/problem/ccc08j3

pos = {'A':(1, 1), 'B':(1, 2), 'C':(1, 3), 'D':(1, 4), 'E':(1, 5), 'F':(1, 6),
       'G':(2, 1), 'H':(2, 2), 'I':(2, 3), 'J':(2, 4), 'K':(2, 5), 'L':(2, 6),
       'M':(3, 1), 'N':(3, 2), 'O':(3, 3), 'P':(3, 4), 'Q':(3, 5), 'R':(3, 6),
       'S':(4, 1), 'T':(4, 2), 'U':(4, 3), 'V':(4, 4), 'W':(4, 5), 'X':(4, 6),
       'Y':(5, 1), 'Z':(5, 2), ' ':(5, 3), '-':(5, 4), '.':(5, 5), '=':(5, 6)}
word = input()
cur = (1, 1)
ans = 0
for i in word:
    nxt = pos[i]
    ans+=abs(cur[0]-nxt[0])+abs(cur[1]-nxt[1])
    cur = nxt
nxt = pos['=']
ans+=abs(cur[0]-nxt[0])+abs(cur[1]-nxt[1])
print(ans)