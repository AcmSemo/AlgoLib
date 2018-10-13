class QuickSort {

  int partition(int array[], int start, int end) {
    int pivot = array[end];
    int i = (start - 1);
    for (int j = start; j < end; j++) {
      if (array[j] <= pivot) {
        i++;
        // array[i] <-> array[j]
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
    // array[i+1] <-> array[end]
    int temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;

    return i + 1;
  }

  void sort(int array[], int start, int end) {
    if (start < end) {
      int partition_index = partition(array, start, end);
      sort(array, start, partition_index - 1);
      sort(array, partition_index + 1, end);
    }
  }
}
