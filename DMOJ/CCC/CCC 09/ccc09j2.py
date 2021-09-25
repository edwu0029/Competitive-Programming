'''
Old Fishin' Hole
Canadian Computing Competition: 2009 Stage 1, Junior #2
https://dmoj.ca/problem/ccc09j2
'''

trout = int(input())
pike = int(input())
pickerel = int(input())
tot = int(input())
cnt = 0
for i in range((tot//trout)+1):
    for j in range((tot//pike)+1):
        for k in range((tot//pickerel)+1):
            if i+j+k!=0 and trout*i+pike*j+pickerel*k<=tot:
                print(f"{i} Brown Trout, {j} Northern Pike, {k} Yellow Pickerel")
                cnt+=1
print(f"Number of ways to catch fish: {cnt}")