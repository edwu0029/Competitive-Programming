'''
Which Alien?
Canadian Computing Competition: 2011 Stage 1, Junior #1
https://dmoj.ca/problem/ccc11j1
'''

antenna = int(input())
eyes = int(input())
if antenna>=3 and eyes<=4:
    print("TroyMartian")
if antenna<=6 and eyes>=2:
    print("VladSaturnian")
if antenna<=2 and eyes<=3:
    print("GraemeMercurian")