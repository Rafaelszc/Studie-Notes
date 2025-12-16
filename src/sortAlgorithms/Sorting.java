package sortAlgorithms;

public class Sorting {
    public static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }

    public static void printArray(int[] arr) {
        System.out.print("{");
        for (int i=0; i<arr.length-1; i++) {
            System.out.printf("%d, ", arr[i]);
        }
        System.out.println(arr[arr.length-1] + "}");
    }
}