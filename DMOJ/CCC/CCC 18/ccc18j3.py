'''
Are we there yet?
Canadian Computing Competition: 2018 Stage 1, Junior #3
https://dmoj.ca/problem/ccc18j3
'''

city1 = 0
city2, city3, city4, city5 = map(int, input().split(' '))
city2+=city1
city3+=city2
city4+=city3
city5+=city4

print(0, abs(city1-city2), abs(city1-city3), abs(city1-city4), abs(city1-city5))
print(abs(city2-city1), 0, abs(city2-city3), abs(city2-city4), abs(city2-city5))
print(abs(city3-city1), abs(city3-city2), 0, abs(city3-city4), abs(city3-city5))
print(abs(city4-city1), abs(city4-city2), abs(city4-city3), 0, abs(city4-city5))
print(abs(city5-city1), abs(city5-city2), abs(city5-city3), abs(city5-city4), 0)