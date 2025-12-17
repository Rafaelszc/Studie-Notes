package sortAlgorithms.selection;

import sortAlgorithms.Sorting;

public class OptSelectionSort extends Sorting {
    public static void sort(int[] arr) {
        for (int i=0; i<arr.length-1; i++) {
            boolean hasSwap = false;
            int min = i;

            for (int j=i+1; j<arr.length; j++) {
                if (arr[j] <= arr[min]) {
                    min = j;
                    hasSwap = true;
                }
            }

            swap(arr, i, min);

            if (!hasSwap) {
                return;
            }
        }
    }
}
