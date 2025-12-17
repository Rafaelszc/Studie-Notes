package sortAlgorithms.quick;

import sortAlgorithms.Sorting;

public class QuickSort extends Sorting {
    public static void sort(int[] arr) {
        sort(arr, 0, arr.length-1);
        printArray(arr);
    }
    private static void sort(int[] arr, int left, int right) {
        if (left < right){
            int pivotIndex = partition(arr, left, right);
            sort(arr, left, pivotIndex - 1);
            sort(arr, pivotIndex + 1, right);
        }
    }
    private static int partition(int[] arr, int left, int right) {
        int pivot = arr[left];
        int i = left;
        int j = right;

        while (i < j) {
            if (arr[j] >= pivot) {
                j--;
            }
            else if (arr[i] <= pivot) {
                i++;
            }
            else swap(arr, i, j);
        }
        swap(arr, left, j);

        return i;
    }

}