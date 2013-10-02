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


