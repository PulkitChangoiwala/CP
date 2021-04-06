import random

t = 100
print(t)
for i in range(t):
	n = random.randint(2,7)
	c = random.randint(2, n*(n+1)/2)
	print(n, end = " ")
	print(c)