/*
* iterator.cpp
* File Name: lab6Exe_B.cpp
* Assignment: ENSF 614 Lab 6, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* ENSF 614 - Fall 2023 - Lab 6, Ex B
* Submission Date: 10 November, 2023.
*/


import java.util.ArrayList;

// MyVector class for managing a collection of items with sorting strategies
public class MyVector<E extends Number & Comparable<E>> {
    private ArrayList<Item<E>> storageM;
    private Sorter<E> sorter;

    public MyVector(int n) {
        storageM = new ArrayList<>(n);
    }

    public MyVector(ArrayList<Item<E>> arr) {
        storageM = new ArrayList<>(arr);
    }

    public void add(Item<E> value) {
        storageM.add(value);
    }

    public void setSortStrategy(Sorter<E> s) {
        sorter = s;
    }

    public void performSort() {
        sorter.sort(storageM);
    }

    public void display() {
        for (Item<E> item : storageM) {
            System.out.print(item.getItem() + " ");
        }
        System.out.println();
    }
}
