package eda;

import java.util.Arrays;
import java.util.Scanner;

public class InsertionSortR {

	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		String[] array = ler.nextLine().split(" ");
		int[] arrayInt = new int[array.length];
		for (int i = 0; i < array.length; i++) {
			arrayInt[i] = Integer.parseInt(array[i]);
		}
		for (int j = 1; j < arrayInt.length; j++) {
			insertionRecursive(arrayInt, j);
			System.out.println(Arrays.toString(arrayInt));
		}

	}

	private static void insertionRecursive(int[] arrayInt, int i) {

		if (i == 0)
			return;
		if (arrayInt[i] < arrayInt[i - 1]) {
			int auxi = arrayInt[i - 1];
			arrayInt[i - 1] = arrayInt[i];
			arrayInt[i] = auxi;
		}
		insertionRecursive(arrayInt, i - 1);
	}

}
