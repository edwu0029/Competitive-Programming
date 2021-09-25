'''
Surmising a Sprinter's Speed
Canadian Computing Competition: 2020 Stage 1, Senior #1
https://dmoj.ca/problem/ccc20s1
'''

N = int(input())
F = []
for i in range(N):
    t, v = map(int, input().split(' '))
    F.append((t, v))
F.sort()
speed = -1.0
for i in range(1, N):
    t2, v2 = F[i][0], F[i][1]
    t1, v1 = F[i-1][0], F[i-1][1]
    curspeed = float(v2-v1)/float(t2-t1)
    if curspeed<0.0:
        curspeed = -curspeed
    if speed<curspeed:
        speed = curspeed
print("%.5f"%speed)