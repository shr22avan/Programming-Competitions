package unnamedEntity;

import fileOperations.FileOperations;
import ioOperations.ConsoleDevice;

public class ApplicationStarter {
	
	public static void start() {
		
		String dataDirectory = null;
		boolean verification, proceed = false;
		ConsoleDevice con = new ConsoleDevice();
		
		while(!proceed) {
			
			con.println("Where is the data?");
			
			dataDirectory = con.nextLine();
			
			verification = FileOperations.exists(dataDirectory);
			
			if(true == verification) {
				proceed = true;	
			}
			
			else {
				con.println("Invalid Location. Lets keep trying . . .");
			}
		}
		
		/* Perform Verification/Analysis Operations on the data in the given location */
		
		Application.startQueryMode();
		
		
		/*
		 * If there are other queries, or parameters required before the program starts,
		 * get them as input here.
		 */
	}
}