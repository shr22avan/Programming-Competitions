import os,time,csv
x=8
n=1000000
N=1
y=0.0
with open('performance9.csv','wb') as myfile:
	writer = csv.writer(myfile,delimiter=',')
	lst=[]
	lst.append('N')
	lst.append('Merge SplitTime')
	lst.append('Sequential Time')
	lst.append('Speedup')
	writer.writerow(lst)
	for i in range(x):
		x=time.time()
		os.system("./a.out "+str(n)+" "+str(N));
		z=time.time() - x
		print n,N,z,
		lst=[]
		lst.append(N)
		#lst.append(N)
		lst.append(z)
		x=time.time()
		os.system("./a.out "+str(n)+" 1");
		Z=time.time() - x
		
		lst.append(Z);
		lst.append(Z/z)
		
		writer.writerow(lst)
		
		print Z,Z/z
		
		N+=1
