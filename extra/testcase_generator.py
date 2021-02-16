import random

f=open('testcases.txt','w')
f.write(str(100))
for j in range(100):
	f.write("\n")
	n = random.randrange(1,1000,1)
	
	k = random.randrange(1,1000, 1)

	f.write(str(n))
	f.write(" ")
	f.write(str(k))
	#print(' ')
	#print (k)
	f.write("\n")
	for i in range(n):
		f.write(str(random.randrange(0,2, 1)))

		#f.write(str(random.randrange(0,2, 1)))
		
		#print(' ')
f.close()

