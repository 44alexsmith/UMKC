
public class Exercise3a_Static_vs_Non_Static {

	    public static void main(String[] args) {
	    	StringBuilder s = new StringBuilder("some value");
	        System.out.println("The original value of s was: " + s );
	    	f(s);
	    	System.out.println("The value of s is now: " + s.toString());
	    }
	    
	    public static StringBuilder f(StringBuilder s) {
	      s.delete(0, s.length());
	      s.append("new value");
	        return s;
	    }
}
