'''
Happy or Sad
Canadian Computing Competition: 2015 Stage 1, Junior #2
https://dmoj.ca/problem/ccc15j2
'''

import sys
input = sys.stdin.readline

N = input()
if N.count(":-)")>N.count(":-("):
    print("happy")
elif N.count(":-)")<N.count(":-("):
    print("sad")
else:
    if N.count(":-)")>0 or N.count(":-(")>0:
        print("unsure")
    else:
        print("none")