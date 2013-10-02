package fileOperations;
import java.io.File;

public class FileOperations {
	/* Class used to define Special File/DIrectory Related Operations */
	
	public static boolean exists(String path) {
		File justChecking = new File(path);
		return justChecking.exists();
	}
	
}