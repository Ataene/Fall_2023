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

// This represents a concrete observer data in a three-column format.
public class ThreeColumnTable_Observer implements Observer {
    private ArrayList<Double> data;

    public ThreeColumnTable_Observer(Subject subject) {
        subject.register(this);
    }

    @Override
    public void update(ArrayList<Double> data) {
        this.data = data;
        display();
    }
    // Display method to show data in three columns.
    public void display() {
        int numRows = (int) Math.ceil(data.size() / 3.0);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < 3; j++) {
                int index = i * 3 + j;
                if (index < data.size()) {
                    System.out.print(data.get(index) + " ");
                }
            }
            System.out.println();
        }
    }
}
