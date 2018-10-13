import java.util.Arrays;

/**
 * In place bubble sort implementation.
 *
 * Complexity:
 *  time: O(n^2)
 *  space: O(1)
 */
public class BubbleSort1 {
    public static void sort(int[] arr) {
        for (int i=0; i < arr.length; i++) {
            for (int k=0; k < arr.length-1; k++)
                if (arr[k+1] < arr[k])
                    swap(arr, k, k+1);
        }
    }

    static void swap(int[] arr, int x, int y) {
        int tmp = arr[x];
        arr[x] = arr[y];
        arr[y] = tmp;
    }

    public static void main(String[] args) {
        int[] arr = {0, 12, 8, -1, 5, 23, 3, 17, 2};
        System.out.printf("Before: %s%n", Arrays.toString(arr));
        sort(arr);
        System.out.printf("After: %s%n", Arrays.toString(arr));
    }
}
