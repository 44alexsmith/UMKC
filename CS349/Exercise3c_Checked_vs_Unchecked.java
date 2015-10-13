import java.io.FileInputStream;
import java.io.FileNotFoundException; 
import java.util.Arrays;
import java.util.Random;

public class Exercise3c_Checked_vs_Unchecked {
	
	public static void main(String args[])
	{
		f(); //Call the routine 	
	}
	
	
	public static void f()
	{
		int c = 0;
		int u = 0;
		int n = 0;
		Random ran = new Random();
		
		int i = 100;
		while(i>0)
		{
			// will return 0, 1 or 2 with equal probability
			int randomNum = ran.nextInt(3); 
			if(randomNum == 0)
			{
				notThrown();
				n++;
			}
			else if(randomNum == 1)
			{
				checked();
				c++;
			}
			else if(randomNum == 2)
			{
				unchecked();
				u++;
			}
			i--;
		}
		System.out.println("Not thrown count is: " + n);
		System.out.println("Checked count is: " + c);
		System.out.println("Unchecked count is: " + u);
	}
	public static void notThrown() 
	{
		//System.out.println("No exception thrown");
	}
	
	public static void checked() //For checked Exceptions
	{
		try  //Try to open a file that doesn't exist
		{
			FileInputStream file = new FileInputStream("C:\\temp\\afile.txt");
		}
		catch(Exception e)
		{
			//System.out.print("Checked Function thrown - specified file cannot be found");
		}	
	}
	
	public static void unchecked() //For unchecked Exceptions
	{
		try{
			int myArray[] = new int[2];
			int val = myArray[3];  //ArrayIndexOutOfBoundsException inherits from RunTimeException
		}catch(Exception e)
		{
			//System.out.println("Unchecked Exception function called - ArrayIndexOutOfBoundsException");
		}
	}
}













/*import java.io.FileInputStream;
import java.io.FileNotFoundException; 
import java.util.Arrays;
import java.util.Random;

public class Exercise3c_Checked_vs_Unchecked {
	
	public static void main(String args[])
	{
		try {
			f(); //Call the routine 	
		}
		catch(IndexOutOfBoundsException | FileNotFoundException ex )
		{
			System.out.println(ex.toString());
		
		}
	}
	
	
	public static void f() throws IndexOutOfBoundsException,FileNotFoundException
	{
		int c = 0;
		int u = 0;
		int n = 0;
		Random ran = new Random();
		
		int i = 100;
		while(i>0)
		{
			// will return 0, 1 or 2 with equal probability
			int randomNum = ran.nextInt(3); 
			if(randomNum == 0)
			{
				notThrown();
				n++;
			}
			else if(randomNum == 1)
			{
				checked();
				c++;
			}
			else if(randomNum == 2)
			{
				unchecked();
				u++;
			}
			i--;
		}
		System.out.println("Not thrown count is: " + n);
		System.out.println("Checked count is: " + c);
		System.out.println("Unchecked count is: " + u);
	}
	public static void notThrown() 
	{
		//System.out.println("No exception thrown");
	}
	
	public static void checked () throws FileNotFoundException //For checked Exceptions
	{
			FileInputStream file = new FileInputStream("C:\\temp\\afile.txt");
			FileNotFoundException fnf = new FileNotFoundException(" File not found");
			throw fnf;
	}
	
	public static void unchecked() throws IndexOutOfBoundsException //For unchecked Exceptions
	{
			int myArray[] = new int[2];
			int val = myArray[3];  //ArrayIndexOutOfBoundsException inherits from RunTimeException
			IndexOutOfBoundsException iob = new IndexOutOfBoundsException("Index out of bounds");
			throw iob;
	}
	

}*/
