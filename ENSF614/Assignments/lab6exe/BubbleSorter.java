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

// BubbleSorter class implementing the Sorter interface
public class BubbleSorter<E extends Number & Comparable<E>> implements Sorter<E> {
    @Override
    public void sort(ArrayList<Item<E>> items) {
        // Bubble sort algorithm
        int n = items.size();
        boolean swapped;
        do {
            swapped = false;
            for (int i = 1; i < n; i++) {
                if (items.get(i - 1).getItem().compareTo(items.get(i).getItem()) > 0) {
                    // Swap items
                    Item<E> temp = items.get(i - 1);
                    items.set(i - 1, items.get(i));
                    items.set(i, temp);
                    swapped = true;
                }
            }
        } while (swapped);
    }
}
