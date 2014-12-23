#!/usr/bin/python

'''
This is a O(n) solution.  Might be possible to improve this.
'''

def is_bouncy(a):
	digits = list(str(a))
	return (sorted(digits) != digits and sorted(digits) != list(reversed(digits)))

bouncy = 0
nonbouncy = 1
num = 1
proportion = 0
while (proportion < .90):
	num = num + 1
	if (is_bouncy(num)):
		bouncy = bouncy + 1
	else:
		nonbouncy = nonbouncy + 1
	proportion = float(bouncy)/float(num)
	print num, bouncy, nonbouncy, proportion