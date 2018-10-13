/* --------------------------
This program takes in integers
as input and outputs them in
ascending sorted order.

This program uses static array
for storage of numbers.

Created by
https://github.com/akshat157
-------------------------- */
#include <stdio.h>                                      // Library inclusion

/* This function takes two integer 
arguments by reference and swaps them. */
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* We pass the array to this function to apply selection sort. */
void selectionSort(int arrayOfNumbers[], int numOfNum)
{
    for (int i = 0; i < numOfNum - 1; i++)              // The actual algorithm is here
        for (int j = i + 1; j < numOfNum; j++)
            if (arrayOfNumbers[i] > arrayOfNumbers[j])
                swap(&arrayOfNumbers[i], &arrayOfNumbers[j]);
}

int main()
{
    int numOfNum = 0;
    printf("Enter the number of numbers you want to sort.\n");
    scanf("%d", &numOfNum);

    if (numOfNum <= 0)
    {
        printf("Invalid input. Exiting!\n");
        return 0;
    }

    int theNumbers[numOfNum];
    printf("Now, enter the numbers to be sorted in a single line separated by spaces.\n");
    
    for (int i = 0; i < numOfNum; i++)          // Take input of the numbers
        scanf("%d", &theNumbers[i]);
    
    selectionSort(theNumbers, numOfNum);

    /* Output the numbers in sorted order */
    for (int i = 0; i < numOfNum; i++)
    {
        printf("%d ", theNumbers[i]);
    }
    printf("\n");

    return 0;
}
