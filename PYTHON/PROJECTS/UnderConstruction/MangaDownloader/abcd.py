import os
class forker :
	
	""" Apostasy's system class. """

	def __enactFork__(self) :

		return os.fork()	
	
	def doFork(self,systemObject) :

		pid = self.__enactFork__()
		
		if pid == 0 :
			
			try :
				systemObject.enact()

			except BaseException:
				raise BaseException("ERROR: Unable to enact function. Closing child process . . .")
				exit(1)
		else : 
			os.wait()

	def __init__(self,systemObject) :
		self.doFork(systemObject)



class wgetForMe :

	""" Specialized command-line class to be used by Apostasy's system classes """

	source = None
 	destination = None

	def __init__(self,s,d) :

		self.source = s
		self.destination = d	

	def enact(self) :

		if self.destination == None :
			raise BaseException("ERROR: Destination url cannot be null. Closing . . .")
			exit(1)
		else :
			print("Executing the command: wget " + self.source + " -O " + self.destination + "\n")
			os.execlp("wget", "wget", self.source, "-O", self.destination)


class getHtmlFromUrl :
        
        url = ''
        _timeout = 5
	_tries = 10
       
	def __init__(self, userUrl) :

                url = userUrl
                
        def getHtmlString() :
                import urllib,sys
		count = _tries
                while count :   
                        try :   
                                f = urllib.urlopen(url)
                                break
                        except Exception :
                                sys.stderr.write("Unable to open url. Retrying . . .")      
                                t = _timeout
				count = count - 1
                                while t>0 :
                                        print(t + "\n")
                                        t = t - 1
                                        sleep(1)
		if count == 0 :
			sys.stderr.write(_tries + " attempts failed. Exiting . . .")

