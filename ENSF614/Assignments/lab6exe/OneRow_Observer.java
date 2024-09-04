/*
* OberserverPatternController.cpp
* File Name: lab6Exe_D.cpp
* Assignment: ENSF 614 Lab 6, exercise D
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* ENSF 614 - Fall 2023 - Lab 6, Ex D
* Submission Date: 10 November, 2023.
*/


import java.util.ArrayList;
// This concrete observer displays single row data
public class OneRow_Observer implements Observer {
    private ArrayList<Double> data;

    public OneRow_Observer(Subject subject) {
        subject.register(this);
    }
    // Update the data to be displayed
    @Override
    public void update(ArrayList<Double> data) {
        this.data = data;
        display();
    }
    // Displays the data 
    public void display() {
        for (Double value : data) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}
