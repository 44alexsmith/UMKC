import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Exercise1c_TwoDimenArray {

	public static void main(String[] args)
	{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int gridSize = 0;
		
		System.out.print("What size x by x grid do you want? ");
		try 
		{
			String input = br.readLine();
			System.out.println("See below for your " + input + " x " + input + " grid!");
			gridSize = Integer.parseInt(input.trim()); //Convert the input String to an Int
		}
		catch(Exception e)
		{
			System.out.println("You entered a invalid input value");
		}
		
				
		char[][] grid = new char[gridSize][gridSize]; //Make a two dimensional grid
		
		for(char[] cell : grid)
		{
			Arrays.fill(cell, 's');	//Fill each sell in the grid		
		}
	

		int k = 1; 
		while(k <= grid.length){System.out.print("+--"); k++;}//Display "+--" plus "+" above the grid
		System.out.print("+"); //Print at the end of the row
		System.out.println(); //Print a new line
		
		for(int i = 0; i < grid.length; i++ ) //For row length
		{
		for(int j = 0; j< grid[i].length; j++) //For column length
			{
				System.out.print("| " + grid[i][j]); //Print one entire row of cells
			}
			System.out.print("|"); //Print at the end of a row
			System.out.println();  //Create a new line at the end of a row
			k=1;
			while(k <= grid.length){System.out.print("+--"); k++;}//Display "+--" plus "+" below each row of cells
			System.out.print("+"); //Print at the end of the row
			System.out.println();  //Print a new line
		}
	}
}












