print("a[1]=1;")
print("a[2]=2")
print("a[3]=3;")
print("a[4]=6;")
print("a[5]=10;")
print("a[6]=20;")
a=20
for i in range(7,100):
	a=a*(i/2)*i/((i/2) * (i - (i/2)))
	print("a["+str(i)+"]=" + str(a) + ";")
