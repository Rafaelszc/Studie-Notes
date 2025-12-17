package sortAlgorithms.insertion;

import sortAlgorithms.Sorting;

public class InsertionSort extends Sorting {
    public static void sort(int[] arr) {
        for (int j=0; j<arr.length; j++) {
            int key = arr[j];

            int i=j;
            while (i>0 && key < arr[i-1]) {
                arr[i] = arr[i-1];
                i--;
            }
            arr[i] = key;
        }
        printArray(arr);
    }
}
