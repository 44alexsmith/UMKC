import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.Vector;

public class Excercise2b_Collection_FileInput {

	public static void main(String[] args) throws Exception {
		FileReader file = new FileReader("C:\\Temp\\input.txt"); //Location of the input file
		BufferedReader reader = new BufferedReader(file); //Link the file to the buffer reader
		
		String text = ""; //Start of a line of data
		String line = reader.readLine(); //Read one line
		while (line != null) //Loop until there are no more lines in the file
		{
			text += line;  //Append to start of a line of data
			line = reader.readLine(); //Advance to the next line
			
		}
		reader.close(); //Close the inputStream file
		System.out.println("Below are the line value(s)that were read in: ");
		System.out.println(text); //Print out each line of data
		
		System.out.println();
		
		//Split the input values based on a comma
		String arrayVals[] = text.split(",");
		
		Vector<Integer> nums = new Vector<Integer>();  //Use of Generics
		for(int i= 0; i < arrayVals.length; i++)
		{
			nums.add(Integer.parseInt(arrayVals[i]));
		}
		
		//Sort the values in the collection
		Collections.sort(nums);
		
		//Print out the values that were read in
		System.out.println("Here are the sorted Collection(Vector)values: ");
		for(Iterator k = nums.iterator(); k.hasNext();)
		{
			System.out.println((Integer)k.next());  //Cast the Iterater values to an integer
		}
	}
}
