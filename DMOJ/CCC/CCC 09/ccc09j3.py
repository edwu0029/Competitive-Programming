'''
Good Times
Canadian Computing Competition: 2009 Stage 1, Junior #3
https://dmoj.ca/problem/ccc09j3
'''

def fix(hour, min):
    if min<0:
        min = 60+min
        hour-=1
    elif min>=60:
        min = min-60
        hour+=1
    if hour<0:
        hour = 24+hour
    elif hour>=24:
        hour = hour-24
    ans = ""
    if hour!=0:
        ans+=str(hour)
    if min<10:
        ans+="0"+str(min)
    else:
        ans+=str(min)
    return ans
time = input()
h, m = 0, 0
if 1<=len(time)<=2:
    h, m = 0, int(time)
else:
    h, m = int(time[:len(time)-2]), int(time[len(time)-2:])
#Ottawa
print(f"{time} in Ottawa")
#Victoria
print(f"{fix(h-3, m)} in Victoria")
#Edmonton
print(f"{fix(h-2, m)} in Edmonton")
#Winnipeg
print(f"{fix(h-1, m)} in Winnipeg")
#Toronto
print(f"{time} in Toronto")
#Halifax
print(f"{fix(h+1, m)} in Halifax")
#St. John's
print(f"{fix(h+1, m+30)} in St. John's")