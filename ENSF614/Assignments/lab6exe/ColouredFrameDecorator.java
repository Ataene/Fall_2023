/*
* DemoDecoratorPatter.java
* File Name: lab6Exe_E.cpp
* Assignment: ENSF 614 Lab 6, exercise E
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* ENSF 614 - Fall 2023 - Lab 6, Ex E
* Submission Date: 10 November, 2023.
*/

import java.awt.Color;
import java.awt.Graphics;

/**
 * The ColouredFrameDecorator class is responsible for adding a colored frame around a component.
 */
public class ColouredFrameDecorator implements Component {
    private Component component;
    private int x;
    private int y;
    private int width;
    private int height;
    private int thickness;

    public ColouredFrameDecorator(Component component, int x, int y, int width, int height, int thickness) {
        this.component = component;
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.thickness = thickness;
    }

    @Override
    public void draw(Graphics g) {
        component.draw(g);
        g.setColor(Color.RED);
        for (int i = 0; i < thickness; i++) {
            g.drawRect(x + i, y + i, width - 2 * i, height - 2 * i);
        }
    }
}
