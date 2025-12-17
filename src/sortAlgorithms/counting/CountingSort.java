package sortAlgorithms.counting;

import sortAlgorithms.Sorting;

public class CountingSort extends Sorting {
    public static void sort(int[] arr) {
        int k = arr[0];

        for (int i=1; i<arr.length; i++) {
            k = Math.max(k, arr[i]);
        }

        int[] arrB = new int[arr.length];
        int[] arrC = new int[k];

        for (int i=0; i<k; i++) {
            arrC[i] = 0;
        }

        for (int i=0; i<arr.length; i++) {
            arrC[arr[i]-1]++;
        }

        for (int i=1; i<k; i++) {
            arrC[i] += arrC[i-1];
        }

        for (int i=arr.length-1; i>=0; i--) {
            arrB[arrC[arr[i]-1]-1] = arr[i];
            arrC[arr[i]-1]--;
        }

        arr = arrB;
        printArray(arr);
    }
}
