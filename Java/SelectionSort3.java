class SelectionSort {
    private void sort(int arr[]) {
        int n = arr.length;

        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n - 1; i++) {
            // Find the minimum element in unsorted array
            int min_idx = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // Swap the found minimum element with the first
            // element
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    private void printArray(int arr[]) {
        for (int anArr : arr) System.out.print(anArr + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        SelectionSort ob = new SelectionSort();
        int arr[] = {4, 72, 11, 85, 92,
                29, 74, 73, 35, 86,
                96, 13, 48, 85, 54,
                81, 79, 96, 7, 52};
        ob.sort(arr);
        ob.printArray(arr);
    }
}
