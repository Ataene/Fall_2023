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

// InsertionSorter class implementing the Sorter interface
public class InsertionSorter<E extends Number & Comparable<E>> implements Sorter<E> {
    public void sort(ArrayList<Item<E>> items) {
        // Insertion sort algorithm
        int n = items.size();
        for (int i = 1; i < n; i++) {
            Item<E> key = items.get(i);
            int j = i - 1;
            while (j >= 0 && items.get(j).getItem().compareTo(key.getItem()) > 0) {
                items.set(j + 1, items.get(j));
                j--;
            }
            items.set(j + 1, key);
        }
    }
}
