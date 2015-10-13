import java.io.Serializable;

	public class UserPreferences implements Serializable {
		     private String directory;
		     private int level;
	
		     public UserPreferences(String directory, int level) {
		         this.directory = directory;
		         this.level = level;
		     }
	
		     public String toString() {
		         return ("Dir=" + directory + ", " + "level=" + level);
		     }
}
