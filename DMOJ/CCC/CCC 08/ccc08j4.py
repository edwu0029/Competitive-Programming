#Problem: https://dmoj.ca/problem/ccc08j4

ops="+-"
while True:
    eq = input()
    if eq=='0':
        break
    ls = eq.split(' ')
    if len(ls)==1:
        print(eq)
        continue
    stk = []
    for i in range(len(ls)-1, -1, -1):
        if ls[i] not in ops:
            stk.append(ls[i])
        else:
            v1, v2 = stk.pop(len(stk)-1), stk.pop(len(stk)-1)
            stk.append(v1+" "+v2+" "+ls[i])
    print(stk[0])