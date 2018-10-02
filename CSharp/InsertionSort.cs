static void InsertionSort(int[] IntegerArray)
{
    for (int i = 1; i < IntegerArray.Length; i++)
    {
        int key = IntegerArray[i];
        int j = i-1;
        while (j>=0 && IntegerArray[j]>key)
        {
            IntegerArray[j+1] = IntegerArray[j];
			j--; 
        }
        IntegerArray[j+1] = key;
    }
}