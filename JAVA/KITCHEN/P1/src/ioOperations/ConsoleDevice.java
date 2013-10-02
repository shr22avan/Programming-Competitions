package ioOperations;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class ConsoleDevice {
	/* Class that handles all input/output operations */
	static InputStream in;
	static PrintStream out;
	
	public ConsoleDevice() {
		in = System.in;
		out = System.out;
	}
	
	public ConsoleDevice(Object i, Object o) {
		/* Requires handling. How do I send the type of the classes as parameters? */
		in = (InputStream) i;
		out = (PrintStream) o;
	}
	
	public void println(String output) {
		(out).println(output);
	}
	
	public String nextLine() {
		Scanner scanIn = new Scanner(in);
		return (String)scanIn.nextLine();
	}
	
	public static InputStream getIn() {
		return in;
	}
	
	public static void setIn(InputStream in) {
		ConsoleDevice.in = in;
	}
	
	public static PrintStream getOut() {
			return out;
	}

	public static void setOut(PrintStream out) {
		ConsoleDevice.out = out;
	}
}