/*
 * Returns position of given value within the sorted array.
 * If Value is not found within the array -1 is returned;
 */
static int BinarySearch(int[] sortedArray, int value)
{
    int min = 0;
    int max = sortedArray.Length;
    
    while(min < max)
    {
        int middle = (min+max)/2;
        
        if(value > sortedArray[middle])
        {
            min = middle;
        }
        else if (value < sortedArray[middle])
        {
            max = middle;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}