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
// Represent the subject in the observer patter
public class DoubleArrayListSubject implements Subject {
    private ArrayList<Observer> observers = new ArrayList<>();
    private ArrayList<Double> data = new ArrayList<>();

    @Override
    public void register(Observer observer) {
        observers.add(observer);
    }

    @Override
    public void remove(Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.update(data);
        }
    }
    // Add or populate the array double
    public void addData(Double value) {
        data.add(value);
        notifyObservers();
    }

    public void setData(Double value, int index) {
        if (index >= 0 && index < data.size()) {
            data.set(index, value);
            notifyObservers();
        }
    }
    // Displays the current data list
    public void populate(double[] values) {
        for (double value : values) {
            data.add(value);
        }
        notifyObservers();
    }

    public void display() {
        if (data.isEmpty()) {
            System.out.println("Empty List ...");
        } else {
            for (Double value : data) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}
