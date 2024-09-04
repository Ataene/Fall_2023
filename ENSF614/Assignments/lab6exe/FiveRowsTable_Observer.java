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
// Concrete Observer displays rows

public class FiveRowsTable_Observer implements Observer {
    private ArrayList<Double> data;
    // Constructor function to register this oberserver
    public FiveRowsTable_Observer(Subject subject) {
        subject.register(this);
    }

    @Override
    public void update(ArrayList<Double> data) {
        this.data = data;
        display();
    }
    // Display the data in 5 rows and columns
    public void display() {
        int numRows = (int) Math.ceil(data.size() / 5.0);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < 5; j++) {
                int index = i * 5 + j;
                if (index < data.size()) {
                    System.out.print(data.get(index) + " ");
                }
            }
            System.out.println();
        }
    }
}
