import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Random;

public class Exercise4a_Throw_Exception {
	static int notExceptionThrown = 0;

	static int testInt;
	static String testString; 
	
	public static void main(String[] args){
	
		for(int i = 0; i < 5; i++)
		{	
			runTestCases(); //Run the test cases 5 times
		}
		
	}
	
	static void runTestCases() // Method to run the test cases
	{
		Random ran = new Random();
		
		int randomNum = ran.nextInt(3); //Create a random number
		if(randomNum == 0)
		{
			testInt = -2;				//Test case 1 - check for < 0
			testString = null;
		}
		else if(randomNum == 1)
		{
			int testInt = 1;              
			String testString = null;	//Test case 2 - check for null
		}
		else if(randomNum == 2)
		{
			testInt = 1;              	//Test case 3 - Check for everything checks out okay
			testString = "Howdy";
		}
	
		try{
			f(testInt,testString);  //Pass in the parameters to the f() function
		}
		catch (IllegalArgumentException e){  //Catch an unchecked exception
			System.out.println("An unchecked exception was thrown. ");
		}
		catch (NoSuchFieldException e){ 	//Catch a checked exception
			System.out.println("A checked exception was thrown. ");
		}
	}
	static void f(int i, String s) throws  IllegalArgumentException, NoSuchFieldException{
			
			if( i < 0)
				throw new IllegalArgumentException();  //Throw unchecked exception
			else if( s == null)
				throw new NoSuchFieldException();  //Throw a checked exception
			else
				System.out.println("No exception thrown"); //No exception to throw
			}
}