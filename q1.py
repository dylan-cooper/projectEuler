#!/usr/bin/python

import math

nums = [3,5]
lcm = 15
below = 1000

total = 0

for num in nums:
	a = math.ceil(float(below)/float(num)) - 1
	b = num*a*(a+1)/2
	total = total + b

c = math.ceil(float(below)/float(lcm)) - 1
d = lcm*c*(c+1)/2
total = total - d

print total