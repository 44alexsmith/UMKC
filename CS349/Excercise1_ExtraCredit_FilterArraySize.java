/*
 Name: Alexeo Smith
 Class: CS 345 Java Applications
 Assignment: Exercise 1 Extra credit
 Write a routine
 String [] FilterByLength(String s[], int i)
 That accepts an array of strings and returns an array that excludes strings of length i.
 Example:
 FilterByLength({“aa”,”b”,”abcd”},1)  {“aa”,”abcd”} 
 */


import org.apache.commons.lang3.ArrayUtils;  //I had to add the commons-lang3-3.4.jar
import java.util.*;
import java.util.Arrays;

public class Excercise1_ExtraCredit_FilterArraySize {
	
	public static void main(String[] args)
	{
		String[] sampleArray = {"aa","b","abcd","c"}; //Original array values
		int filterValue = 4; //Array items with a size of this value i.e. the filter value
		
		//Function to print out the filtered values
		System.out.println("Filtered array values:" + Arrays.toString(FilterByLength(sampleArray,filterValue)));
	}
	
	static String[] FilterByLength(String oldArray[], int input)
	{
		{
			System.out.println("Original array values: " + Arrays.toString(oldArray)); //Print the 
			for(int k =0; k < oldArray.length; k++)                                    //original array values
			{
				if(oldArray[k].length() == input ) //If the array element is equal to the size of 
				{	                               // input value, delete that array element at index k
					oldArray = ArrayUtils.remove(oldArray, k);
				}		
			}
			return oldArray; //Returned the modified array
		}
	}		
}
