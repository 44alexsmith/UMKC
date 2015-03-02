/*Class: CS 371
  Name: Alexeo Smith
  Assignment: HW #2
  Date: 2/28/2015
  Purpose: Show how to make a Java GUI application using WindowBuilder in Eclipse
*/

package xHelloWorldGUI;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class xHelloWorldGUI {

	private JFrame frame;
	private JTextField tfName;
	
	private JLabel lblMsg;  //Define lblMsg as a private member variable
	

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					xHelloWorldGUI window = new xHelloWorldGUI();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public xHelloWorldGUI() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblName = new JLabel("Name");
		
		lblName.setBounds(15, 35, 69, 20);
		frame.getContentPane().add(lblName);
		
		tfName = new JTextField();
		tfName.setBounds(101, 32, 146, 26);
		frame.getContentPane().add(tfName);
		tfName.setColumns(10);
		
		JButton btnHi = new JButton("Hi");
		btnHi.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				String name = tfName.getText();
				lblMsg.setText("Hi " + name);
			}
		});
		btnHi.setBounds(15, 81, 115, 29);
		frame.getContentPane().add(btnHi);
		
		lblMsg = new JLabel("");
		lblMsg.setBounds(15, 152, 115, 41);
		frame.getContentPane().add(lblMsg);
	}
}
