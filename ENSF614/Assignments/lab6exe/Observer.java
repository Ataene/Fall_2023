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

// This interface defines the contract for all observers in the observer pattern.
public interface Observer {
    void update(ArrayList<Double> data);
}
