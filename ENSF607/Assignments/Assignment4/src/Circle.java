/*
 * Class Shape, Rectangle, and Circle to implement
 * Open/Closed Principle(OCP)
 * 
 * 
 */

public class Circle extends Shape {
    private double radius;

    public Circle(double radius) { // COn
        this.radius = radius;
    }

    @Override
    public double area() {
        return Math.PI * radius * radius;
    }
}
