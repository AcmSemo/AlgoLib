public class Bubblesort {
    
    public int[] sort(int[] array){
        int length = array.length;
        int temp;
        for(int i=0; i < length; i++) {
            for (int j = 1; j < (length - i); j++) {
                if (array[j - 1] > array[j]) {
                    temp = array[j - 1];
                    array[j - 1] = array[j];
                    array[j] = temp;
                }
            } 
        }
        return array;
    }
}
