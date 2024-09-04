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
// The BorderDecorator class is responsible for decorating a component.
public class BorderDecorator implements Component {
    private Component component;
    private int x;
    private int y;
    private int width;
    private int height;

    public BorderDecorator(Component component, int x, int y, int width, int height) {
        this.component = component;
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }
 /**
     * Draws the component with the added border on the provided Graphics object.
     * 
     * @param g The Graphics object to draw the component with a border.
     */

    @Override
    public void draw(Graphics g) {
        component.draw(g);
    }
}
