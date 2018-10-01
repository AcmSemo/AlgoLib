public static int[] BubbleSort(int[] listOfNumbers)
{
    for (int i = 0; i < listOfNumbers.Length - 1; i++)
    {
        for (int j = 0; j < listOfNumbers.Length - i - 1; j++)
        {
            if (listOfNumbers[j] > listOfNumbers[j + 1])
            {
                int temp = listOfNumbers[j + 1];
                listOfNumbers[j + 1] = listOfNumbers[j];
                listOfNumbers[j] = temp;
            }
        }
    }
    return listOfNumbers;
}