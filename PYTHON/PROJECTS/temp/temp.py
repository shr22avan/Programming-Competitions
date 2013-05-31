import os
k='A'
while(k<='Z'):
	pid=os.fork()
	if pid==0:
		os.execlp("wget","wget","http://www.dmoz.org/Arts/Music/Bands_and_Artists/"+k+"/","-O","/home/shravan/PYTHON/PROJECTS/temp/pages/"+k+".html")		
	else :
		k=chr(ord(k)+1)
		os.wait()

