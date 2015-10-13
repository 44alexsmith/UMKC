import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.awt.geom.*;
import java.text.DecimalFormat;
import java.util.*;
 
@SuppressWarnings("serial")
public class Exercise5a_Sketching extends JFrame
{
        // Contains all of the rules for drawing
        Graphics2D graphicSettings;
       
        // Default stroke and fill colors 
        Color strokeColor=Color.BLACK,fillColor=Color.BLACK;
        
        public Exercise5a_Sketching()
        {
            // Define the defaults for the JFrame
            this.setSize(700,700);
            this.setTitle("Java Paint");
            this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                
            // Make the drawing area take up the center of the fram
            this.add(new DrawingBoard(), BorderLayout.CENTER);
             
            // Show the frame
            this.setVisible(true);
        }
        
        private class DrawingBoard extends JComponent
        {
             
            	// ArrayList container for the shape
                ArrayList<Shape> shapes = new ArrayList<Shape>();
                
        
                //Start and end point 
                Point drawStart, drawEnd;
 
                // Monitors events on the drawing area of the frame
                public DrawingBoard()
                {
                        this.addMouseMotionListener(new MouseMotionAdapter()
                        {
                          public void mouseDragged(MouseEvent e)
                          {             
                                
                        	  int x = e.getX();
                              int y = e.getY();
                               
                              int oldX = x;
                              int oldY = y;
                              
                              Shape aShape = null;
                              
                        	  aShape = drawLine(oldX,oldY,e.getX(),e.getY());
                        	  shapes.add(aShape);
                            
                               
                              // Get the final x & y position after the mouse is dragged
                              drawEnd = new Point(e.getX(), e.getY());
                              repaint();
                        	  
                          }
                        } );
                }
                 
                public void paint(Graphics g)
                {
                		// Class used to define the shapes to be drawn
                        graphicSettings = (Graphics2D)g;
 
                        // Antialiasing cleans up the jagged lines and defines rendering rules
                        graphicSettings.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                                RenderingHints.VALUE_ANTIALIAS_ON);
                         
                        // Defines the line width of the stroke
                        graphicSettings.setStroke(new BasicStroke(5));
 
                       
                       for (Shape s : shapes)
                        {
                            graphicSettings.draw(s);
                        }
                }
 
               private Line2D.Double drawLine( int x1, int y1, int x2, int y2)
               {   
            	   return new Line2D.Double(x1, y1, x2, y2);
               }
        }
        
        public static void main(String [] args)
        {
                new Exercise5a_Sketching();
        }
 
}

