
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


