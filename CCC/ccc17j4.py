#Problem: https://dmoj.ca/problem/ccc17j4

memo = [0 for i in range(722)]
hour = 12
minute = 0
def check(hour, minute):
    h = str(hour)
    m = str(minute)
    if minute<10:
        m = '0'+m
    time = h+m
    F = [0 for i in range(len(time))]
    for i in range(len(time)):
        F[i] = int(time[i])
    d = F[1]-F[0]
    for i in range(1, len(F)):
        if F[i]-d!=F[i-1]:
            return False
    return True
cnt = 0
for i in range(721):
    minute+=1
    if minute>=60:
        minute = 0
        hour+=1
    if hour>12:
        hour = 1
    if check(hour, minute):
        cnt+=1
    memo[i+1] = cnt

D = int(input())
print(memo[D%720]+int(D/720)*memo[720])
