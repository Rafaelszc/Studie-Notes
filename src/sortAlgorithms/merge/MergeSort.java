package sortAlgorithms.merge;

import sortAlgorithms.Sorting;

public class MergeSort extends Sorting {
    public static void sort(int[] arr) {
        sort(arr, 0, arr.length-1);
        printArray(arr);
    }
    private static void sort(int[] arr, int left, int right) {
        if (left<right) {
            int middle = left + (right - left) / 2;
            sort(arr, left, middle);
            sort(arr, middle + 1, right);
            mergeLists(arr, left, middle, right);
        }
    }
    private static void mergeLists(int[] arr, int left, int middle, int right) {
        int lengthLeft = middle - left + 1;
        int lengthRight = right - middle;
        int resultIndex = left;
        int leftIndex = 0;
        int rightIndex = 0;

        int[] arrLeft = new int[lengthLeft];
        int[] arrRight = new int[lengthRight];

        for (int i=0; i<lengthLeft; i++) {
            arrLeft[i] = arr[left+i];
        }
        for (int i=0; i<lengthRight; i++) {
            arrRight[i] = arr[middle+i+1];
        }

        while (leftIndex < lengthLeft && rightIndex < lengthRight) {
            if (arrLeft[leftIndex] <= arrRight[rightIndex]) {
                arr[resultIndex] = arrLeft[leftIndex];
                leftIndex++;
            }
            else {
                arr[resultIndex] = arrRight[rightIndex];
                rightIndex++;
            }
            resultIndex++;
        }
        while (leftIndex<lengthLeft) {
            arr[resultIndex] = arrLeft[leftIndex];
            leftIndex++;
            resultIndex++;
        }
        while (rightIndex<lengthRight) {
            arr[resultIndex] = arrRight[rightIndex];
            rightIndex++;
            resultIndex++;
        }
    }
}