/*
 * Class Shape, Rectangle, and Circle to implement
 * Open/Closed Principle(OCP)
 * 
 * 
 */

public class Rectangle extends Shape {
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public double area() {
        return width * height;
    }
}