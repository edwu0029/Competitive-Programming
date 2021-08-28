#Problem: https://dmoj.ca/problem/ccc12j3

K = int(input())
ch = [['*', 'x', '*'], [' ', 'x', 'x'], ['*', ' ', '*']]
for a in range(3):
    for b in range(K):
        for c in range(3):
            for d in range(K):
                print(ch[a][c], end="")
        print()