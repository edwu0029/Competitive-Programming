#Problem: https://dmoj.ca/problem/ccc11j4

b = [[False for _ in range(500)] for _ in range(500)]
b[1][250] = True
b[2][250] = True
b[3][250] = True
b[3][251] = True
b[3][252] = True
b[3][253] = True
b[4][253] = True
b[5][253] = True
b[5][254] = True
b[5][255] = True
b[4][255] = True
b[3][255] = True
b[3][256] = True
b[3][257] = True
b[4][257] = True
b[5][257] = True
b[6][257] = True
b[7][257] = True
b[7][256] = True
b[7][255] = True
b[7][254] = True
b[7][253] = True
b[7][252] = True
b[7][251] = True
b[7][250] = True
b[7][249] = True
b[6][249] = True
b[5][249] = True
curr, curc = 5, 249
while True:
    dir, c = input().split(' ')
    c = int(c)
    blocked = False
    if dir=='q':
       break
    for i in range(c):
        if dir=='l':
            curc-=1
        elif dir=='r':
            curc+=1
        elif dir=='u':
            curr-=1
        elif dir=='d':
            curr+=1
        if b[curr][curc]:
            blocked = True
        b[curr][curc] = True
    if blocked:
        print(curc-250, -curr, "DANGER")
        break
    else:
        print(curc-250, -curr, "safe")
