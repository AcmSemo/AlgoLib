int[] SelectionSort(int[] listOfNumbers)
{
    for (int x = 0; x < listOfNumbers.Length; x++)
    {
        int min = x;
        for (int j = x; j < listOfNumbers.Length; j++)
        {
            if (listOfNumbers[j] < listOfNumbers[min])
            {
                min = j;
            }
        }
        int temp = listOfNumbers[x];
        listOfNumbers[x] = listOfNumbers[min];
        listOfNumbers[min] = temp;
    }

    return listOfNumbers;
}