/*
* OberserverPatternController.cpp
* File Name: lab6Exe_D.cpp
* Assignment: ENSF 614 Lab 6, exercise D
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* ENSF 614 - Fall 2023 - Lab 6, Ex D
* Submission Date: 10 November, 2023.
*/

public interface Subject {
    void register(Observer observer); // Register the observer
    void remove(Observer observer);
    void notifyObservers(); // Notify all registered Oberser.
}
