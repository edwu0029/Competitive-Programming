'''
Body Mass Index
Canadian Computing Competition: 2008 Stage 1, Junior #1
https://dmoj.ca/problem/ccc08j1
'''

w = float(input())
h = float(input())
bmi = w/(h*h)
if bmi>25.0:
    print("Overweight")
elif bmi<18.5:
    print("Underweight")
else:
    print("Normal weight")