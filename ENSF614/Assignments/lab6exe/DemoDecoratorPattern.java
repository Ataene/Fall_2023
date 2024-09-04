/*
* DemoDecoratorPatter.java
* File Name: lab6Exe_E.cpp
* Assignment: ENSF 614 Lab 6, exercise E
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* ENSF 614 - Fall 2023 - Lab 6, Ex E
* Submission Date: 10 November, 2023.
*/

import java.awt.Font;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;


public class DemoDecoratorPattern extends JPanel {
	Component t;
	
    public DemoDecoratorPattern(){
   	 t = new Text ("Hello World", 60, 80); 
   }
	
    // public void paintComponent(Graphics g){
 	//     int fontSize = 10;
 	//     g.setFont(new Font("TimesRoman", Font.PLAIN, fontSize));
 	    
 	//     // Now lets decorate t with BorderDecorator: x = 30, y = 30, width = 100, and height 100
 	//     t = new BorderDecorator(t, 30, 30, 100, 100);
 	   
 	//     // Now lets add a ColouredFrameDecorator with x = 25, y = 25, width = 110, height = 110,
 	// 	// and thickness = 10.
 	//     t = new ColouredFrameDecorator(t, 25, 25, 110, 110, 10);
 
 	//     // Now lets draw the product on the screen 	 
 	//     t.draw(g);
    // }

		/*
	* DemoDecoratorPatter.java
	* File Name: lab6Exe_F.cpp
	* Assignment: ENSF 614 Lab 6, exercise F
	* Created by Mahmood Moussavi
	* Completed by: Emmanuel Alafonye
	* ENSF 614 - Fall 2023 - Lab 6, Ex F
	* Submission Date: 10 November, 2023.
	*/

	public void paintComponent(Graphics g) {
		int fontSize = 10;
		g.setFont(new Font("TimesRoman", Font.PLAIN, fontSize));
	
		// Decorate 't' with a ColouredGlassDecorator, ColouredFrameDecorator, and BorderDecorator.
		t = new ColouredGlassDecorator(new ColouredFrameDecorator(new BorderDecorator(t, 30, 30, 100, 100), 25, 25, 110, 110, 10), 25, 25, 110, 110);
	
		t.draw(g);
	}
	
	
	public static void main(String[] args) {	
        DemoDecoratorPattern panel = new DemoDecoratorPattern();
        JFrame frame = new JFrame("Learning Decorator Pattern");
        frame.getContentPane().add(panel);
        frame.setSize(400,400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
	}
}