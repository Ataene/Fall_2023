/*
* iterator.cpp
* File Name: lab6Exe_C.cpp
* Assignment: ENSF 614 Lab 6, exercise C
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* ENSF 614 - Fall 2023 - Lab 6, Ex C
* Submission Date: 10 November, 2023.
*/

import java.util.ArrayList;

public class SelectionSorter<E extends Number & Comparable<E>> implements Sorter<E> {
    @Override
    public void sort(ArrayList<Item<E>> items) {
        // Selection sort algorithm
        int n = items.size();

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < n; j++) {
                if (items.get(j).getItem().compareTo(items.get(minIndex).getItem()) < 0) {
                    minIndex = j;
                }
            }
            // Swap items
            Item<E> temp = items.get(minIndex);
            items.set(minIndex, items.get(i));
            items.set(i, temp);
        }
    }
}
