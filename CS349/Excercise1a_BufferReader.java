

import java.io.BufferedReader;
import java.util.*;
import java.io.*;

public class Excercise1a_BufferReader {
	
	public static void main(String[] args)
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.println("What is your name? ");
		try 
		{
			String name = br.readLine();
			System.out.println("That's a kewl name, " + name + "!");
		}
		catch(Exception e)
		{
			System.out.println("Houston, we have a problem");
		}
	}
}
