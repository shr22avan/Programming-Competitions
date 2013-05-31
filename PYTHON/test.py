import math
def gcd(a,b):
	while a!=b:
		if a>b:
			return gcd(a-b,b)
		else:
			return gcd(a,b-a)
	return a

def totient(n):
	count=0
	for i in range(1,n):
		if gcd(i,n)==1:
			count=count+1
	return count 

for i in range(1,990):
	print str(i)+":"+str(totient(i))+":"+str(totient(i)/(i*1.0))
