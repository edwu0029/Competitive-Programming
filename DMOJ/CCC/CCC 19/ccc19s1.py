'''
Flipper
Canadian Computing Competition: 2019 Stage 1, Junior #4, Senior #1
https://dmoj.ca/problem/ccc19s1
'''

H = [[1, 2], [3, 4]]
def h_flip():
    tmp = H[0][0]
    H[0][0] = H[1][0]
    H[1][0] = tmp
    tmp2 = H[0][1]
    H[0][1] = H[1][1]
    H[1][1] = tmp2
def v_flip():
    tmp = H[0][0]
    H[0][0] = H[0][1]
    H[0][1] = tmp
    tmp2 = H[1][0]
    H[1][0] = H[1][1]
    H[1][1] = tmp2

instructions = input()
for i in instructions:
    if i=='H':
        h_flip()
    else:
        v_flip()
print(str(H[0][0])+' '+str(H[0][1]))
print(str(H[1][0])+' '+str(H[1][1]))
