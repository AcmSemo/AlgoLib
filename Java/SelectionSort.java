import java.util.Arrays;

/**
 * In-place selection sort implementation.
 *
 * Complexity:
 *   time:  O(n^2)
 *   space: O(1)
 */
public class SelectionSort {

    /**
     * Takes an array of integers and sorts to ascending order.
     * @param arr
     */
    public static void sort(int[] arr) {
        for (int i=0; i < arr.length; i++) {
            /* loop through each sub-array, and find min element */
            int minPos = findMinPos(arr, i);
            if (i != minPos) {
                swap(arr, i, minPos);
            }
        }
    }

    /*
     * Returns the position of the min element in
     * array arr starting at startPos.
     */
    static int findMinPos(int[] arr, int startPos) {
        int minPos = startPos;
        for (int i=startPos+1; i < arr.length; i++)
            if (arr[i] < arr[minPos])
                minPos = i;
        return minPos;
    }

    /* If applicable, swaps arr elements at a and b. */
    static void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    public static void main(String[] args) {
        int[] arr = {9, 12, 11, 3, 17, 2, 1, 8, -6};

        System.out.printf("Before: %s%n", Arrays.toString(arr));
        sort(arr);
        System.out.printf("After: %s%n", Arrays.toString(arr));
    }
}