
import java.io.*;

public class Exercise3d_Serialization {

	public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
		
        //Read in an object
		ObjectInputStream in =  new ObjectInputStream(new FileInputStream("C:\\Users\\a-smi_000\\Documents\\Now\\Lab3Object2.ser.txt"));
        
		//Cast the object to the PersistentStorage class
		PersistentStorage ps = (PersistentStorage)in.readObject();
        
		//Print out the InstancSecret and Computed Secret
		System.out.println("The Instance Secret is: " + ps.getInstanceSecret());
        System.out.println("The Computer Secret is: " + ps.getComputedSecret());
        in.close();
	}
}
