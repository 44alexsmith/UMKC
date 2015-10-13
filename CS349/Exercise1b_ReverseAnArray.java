

	
import java.util.*;

public class Exercise1b_ReverseAnArray {

	public static void main(String[] args)
	{
		
		int[] sampleArray = {1,2,3,4,5};  //Make a Sample array
		
		System.out.println("The original array values: "); 
		System.out.println(Arrays.toString(sampleArray)); //Print the original array values
		
		System.out.println("The reversed array values: "); 
		System.out.println(Arrays.toString(reverseArrayFunc(sampleArray))); //Call a function to reverse the 
																			//the sample array values and display
		 																	//the result
	}
	
	public static int[] reverseArrayFunc(int[] originalArray)
	{
		int[] reversedArray = new int[originalArray.length]; //Set the size of the rev. Array to the size of the orig. array.
		int j = reversedArray.length -1; 					//Set j to the size of the reversed array length - 1
		
		for(int i = 0; i < originalArray.length; i++) //increment i
		{		
				reversedArray[j] = originalArray[i]; //Set the reversed array to the values of the original array but in
				            						//reverse order 
				j--;								//decrement j
		}
		return reversedArray; //return the reversed array to the calling function
		
	}
}


