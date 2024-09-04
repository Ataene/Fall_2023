/*
* DemoDecoratorPatter.java
* File Name: lab6Exe_E.cpp
* Assignment: ENSF 614 Lab 6, exercise E
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* ENSF 614 - Fall 2023 - Lab 6, Ex E
* Submission Date: 10 November, 2023.
*/

import java.awt.Graphics;
// Represent component to be drawned
public class Text implements Component {
    private String text;
    private int x;
    private int y;

    public Text(String text, int x, int y) {
        this.text = text; // The diplayed Text
        this.x = x;
        this.y = y;
    }
    // Draws the text on the Graphics
    @Override
    public void draw(Graphics g) {
        g.drawString(text, x, y);
    }
}
