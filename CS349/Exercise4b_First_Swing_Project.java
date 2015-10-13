
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.LayoutManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

class Exercise4b_First_Swing_Project extends JFrame implements ActionListener{
	
	//Create two buttons
    JButton next  = new JButton("Next");    
    JButton previous = new JButton("Prev");

    //Create a text Filed component
    JTextField numTextField = new JTextField("1",2);
    JLabel ofFive = new JLabel(" of 5");
   
    Container contentPane = getContentPane();
    
	public Exercise4b_First_Swing_Project() {

			//Prevent number input for the text field	
			numTextField.setEnabled(false);
			previous.setEnabled(false); //Set the initial previous state
			
	        
	        //Frame title
	        this.setTitle("Photo Album");
	        
	        //Create an image
	        ImageIcon image = new ImageIcon("vader2.png");
	        JLabel labelCenter = new JLabel("", image, JLabel.CENTER);
	        
	        //Display an image in middle quadrant
	        contentPane.add(labelCenter, BorderLayout.CENTER);
	        
	        //Create an inner layout panel that has a Flowlayout
	        JPanel innerContainerPanel = new JPanel();
	       
	        
	        //Add an anonymous actionListener event to the Next button
	        next.addActionListener(new ActionListener() {
	            public void actionPerformed(ActionEvent evt) {
	            	Integer number = Integer.parseInt(numTextField.getText());
	            	if(number == 5)
	            	{
	            		next.setEnabled(false);
	            		previous.setEnabled(true);
	            	}
	            	else if(number != 5)
	            	{
	            		next.setEnabled(true);
	            		previous.setEnabled(true);
	            		number++;
	            		if(number == 5)
	            			next.setEnabled(false);
	            		String val = Integer.toString(number);
	            		numTextField.setText(val); 
	            	}
	            }  
	        });
	        
	        //Add an anonymous actionListener event to the Previous button
	        previous.addActionListener(new ActionListener() {
	            public void actionPerformed(ActionEvent evt) {
	            	Integer number = Integer.parseInt(numTextField.getText());
	            	if(number == 1)
	            	{	
	            		previous.setEnabled(false);
	            		next.setEnabled(true);
	            	}
	            	else if(number != 1 )
	            	{
	            		previous.setEnabled(true);
	            		next.setEnabled(true);
	            		number--;
	            		if(number == 1)
		            		previous.setEnabled(false);
	            		String val = Integer.toString(number);
	            		numTextField.setText(val); 
	            	}
	            } 
	        });
	        
	        //Add the components to the inner container panel
	        innerContainerPanel.add(numTextField);
	        innerContainerPanel.add(ofFive);
	        innerContainerPanel.add(next);
	        innerContainerPanel.add(previous);
	        
	        //Now add the inner container to the outer container
	        contentPane.add(innerContainerPanel,BorderLayout.SOUTH);
		
	}	       
	      
	public static void main(String[] args) {
		
		 JFrame frame = new Exercise4b_First_Swing_Project(); //Kick off the class
	     frame.pack();  //Sets with and height based on size of container components
	     frame.setVisible(true); //Make the frame visible
	}	
}
