'''
Wait Time
Canadian Computing Competition: 2015 Stage 1, Junior #4
https://dmoj.ca/problem/ccc15j4
'''

M = int(input())
time= 0
recieved = {}
done = {}
wait = {}
pre = ''
for i in range(M):
    op, x = input().split(' ')
    x = int(x)
    if op=='W':
        time+=x
        if pre=='R' or pre=='S':
            time-=1
        pre = 'W'
        continue
    if x not in wait:
        wait[x] = 0
        done[x] = False
    if op=='R':
        recieved[x] = time
        done[x] = False
        pre = 'R'
    elif op=='S':
        wait[x]+=time-recieved[x]
        recieved[x] = time
        done[x] = True
        pre = 'S'
    time+=1
wait = dict(sorted(wait.items()))
print()
for i in wait.keys():
    if done[i]:
        print(i, wait[i])
    else:
        print(i, -1)
