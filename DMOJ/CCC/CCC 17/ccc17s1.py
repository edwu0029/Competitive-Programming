#Problem: https://dmoj.ca/problem/ccc17s1

N = int(input())
swift = list(map(int, input().split(' ')))
semaphores = list(map(int, input().split(' ')))
s1 = 0
s2 = 0
cnt = 0
for i in range(N):
    s1+=swift[i]
    s2+=semaphores[i]
    if s1==s2:
        cnt = i+1
print(cnt)
