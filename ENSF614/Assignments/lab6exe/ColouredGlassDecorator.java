/*
* DemoDecoratorPatter.java
* File Name: lab6Exe_F.cpp
* Assignment: ENSF 614 Lab 6, exercise F
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* ENSF 614 - Fall 2023 - Lab 6, Ex F
* Submission Date: 10 November, 2023.
*/

import java.awt.Graphics;
import java.awt.Color;
import java.awt.Graphics2D;

public class ColouredGlassDecorator implements Component {
    private Component component;
    private int x;
    private int y;
    private int width;
    private int height;

    public ColouredGlassDecorator(Component component, int x, int y, int width, int height) {
        this.component = component;
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    @Override
    public void draw(Graphics g) {
        component.draw(g);

        // Add green glass cover with transparency
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(new Color(0, 255, 0, 128));  // Transparent green color
        g2d.fillRect(x, y, width, height);
    }
}
