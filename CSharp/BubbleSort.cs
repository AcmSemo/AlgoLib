namespace Program
{
    public class Sort
    {
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

        public static void Main(string[] Args)
        {
            int[] list = { 7, 4, 6, 10, 8, 3, 5, 9, 2, 1 };
            BubbleSort(list);
            foreach (var item in list)
            {
                System.Console.Out.WriteLine(item + ", ");
            }
        }
    }
}