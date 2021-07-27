#Problem: https://dmoj.ca/problem/ccc10j3

m = {'A': 0, 'B': 0}
while True:
    line = input()
    op = int(line[0])
    if op==1:
        X, n = line[2], int(line[4:])
        m[X] = n
    elif op==2:
        X = line[2]
        print(m[X])
    elif op==3:
        X, Y = line[2], line[4]
        m[X] = m[X]+m[Y]
    elif op==4: 
        X, Y = line[2], line[4]
        m[X] = m[X]*m[Y]
    elif op==5:
        X, Y = line[2], line[4]
        m[X] = m[X]-m[Y]
    elif op==6:
        X, Y = line[2], line[4]
        m[X] = m[X]//m[Y]
    elif op==7:
        break