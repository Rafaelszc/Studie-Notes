package sortAlgorithms.selection;

import sortAlgorithms.Sorting;

public class SelectionSort extends Sorting {
    public static void sort(int[] arr) {
        for (int i=0; i<arr.length-1; i++) {
            int min = i;
            for (int j=i+1; j<arr.length; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            swap(arr, i, min);
        }
        printArray(arr);
    }
}
