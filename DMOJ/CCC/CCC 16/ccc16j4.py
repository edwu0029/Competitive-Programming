'''
Arrival Time
Canadian Computing Competition: 2016 Stage 1, Junior #4
https://dmoj.ca/problem/ccc16j4
'''

S = input()
hour = int(S[0:2])
minute = int(S[3:])
time = (hour*60)+minute
cnt = 240
while cnt>0:
    if (time>=420 and time<600) or (time>=900 and time<1140):
        cnt-=1
    else:
        cnt-=2
    time+=1

hourT = int(time/60)
if hourT>24:
    hourT = 1
elif hourT==24:
    hourT = 0
minuteT = int(time%60)
if hourT<10:
    if minuteT<10:
        print("0"+str(hourT)+":0"+str(minuteT))
    else:
        print("0"+str(hourT)+":"+str(minuteT))
else:
    if minuteT<10:
        print(str(hourT)+":0"+str(minuteT))
    else:
        print(str(hourT)+":"+str(minuteT))