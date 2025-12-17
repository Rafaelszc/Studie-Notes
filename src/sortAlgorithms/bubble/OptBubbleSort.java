package sortAlgorithms.bubble;

import sortAlgorithms.Sorting;

public class OptBubbleSort extends Sorting {
    public static void sort(int[] arr) {
        for(int i=0; i<arr.length; i++) {
            boolean hasSwap = false;

            for(int j=1; j<arr.length-i; j++) {
                if (arr[j] < arr[j-1]) {
                    swap(arr, j, j-1);
                    hasSwap = true;
                }
            }
            if (!hasSwap) {
                printArray(arr);
                return;
            }
        }
        printArray(arr);
    }
}
