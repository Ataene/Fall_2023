/*
* iterator.cpp
* File Name: lab6Exe_B.cpp
* Assignment: ENSF 614 Lab 6, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* ENSF 614 - Fall 2023 - Lab 6, Ex B
* Submission Date: 10 November, 2023.
*/

import java.util.Random;

public class DemoStrategyPattern {
	public static void main(String[] args) {
		// Create an object of MyVector<Double> with a capacity of 50 elements
		MyVector<Double> v1 = new MyVector<>(50);

		// Create a Random object to generate values between 0
		Random rand = new Random();

		// Adding 5 randomly generated numbers into MyVector object v1
		for (int i = 4; i >= 0; i--) {
			Item<Double> item = new Item<>(rand.nextDouble() * 100);
			v1.add(item);
		}

		// Displaying original data in MyVector v1
		System.out.println("The original values in v1 object are:");
		v1.display();

		// Choose the bubble sort algorithm as a strategy to sort object v1
		v1.setSortStrategy(new BubbleSorter<>());
		v1.setSortStrategy(new SelectionSorter<>());

		// Perform algorithm bubble sort on v1
		v1.performSort();

		System.out.println("\nThe values in MyVector object v1 after performing BubbleSorter are:");
		v1.display();

		// Create a MyVector<Integer> object v2
		MyVector<Integer> v2 = new MyVector<>(50);

		// Populate v2 with 5 randomly generated numbers
		for (int i = 4; i >= 0; i--) {
			Item<Integer> item = new Item<>(rand.nextInt(50));
			v2.add(item);
		}

		System.out.println("\nThe original values in v2 object are:");
		v1.performSort();
		v2.display();
		v2.setSortStrategy(new InsertionSorter<>());
		v2.performSort();

		System.out.println("\nThe values in MyVector object v1 after performing SelectionSorter is:");
		v1.display();
		System.out.println("\nThe values in MyVector object v2 after performing InsertionSorter are:");
		v2.display();
	}
}
