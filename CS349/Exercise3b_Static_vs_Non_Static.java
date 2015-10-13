
public class Exercise3b_Static_vs_Non_Static {
	    public static void main(String[] args) {
	        StringBuffer s = new StringBuffer("some value");
	        f(s);
	        System.out.println(s.toString());
	    }

	    public static StringBuffer f(StringBuffer s) {
	        s.delete(0, s.length());
		    s.append("value");
		        return s;
	    }
}
