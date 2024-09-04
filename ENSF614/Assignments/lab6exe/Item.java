/*
* iterator.cpp
* File Name: lab6Exe_B.cpp
* Assignment: ENSF 614 Lab 6, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* ENSF 614 - Fall 2023 - Lab 6, Ex B
* Submission Date: 10 November, 2023.
*/


public class Item<E extends Number & Comparable<E>> {
    private E item;

    public Item(E value) {
        item = value;
    }

    public void setItem(E value) {
        item = value;
    }

    public E getItem() {
        return item;
    }
}
