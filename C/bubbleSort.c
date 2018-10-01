#include <stdio.h> 
  
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int numOfNum = 0;
    printf("Enter the number of numbers you want to sort:\n");
    scanf("%d", &numOfNum);

    if (numOfNum <= 0)
    {
        printf("Invalid input. Exiting!\n");
        return 0;
    }

    int theNumbers[numOfNum];
    printf("Now, enter the numbers to be sorted in a single line separated by spaces\n");
    
    for (int i = 0; i < numOfNum; i++)          // Take input of the numbers
        scanf("%d", &theNumbers[i]);
    
    bubbleSort(theNumbers, numOfNum); 
    
    printf("Sorted list of numbers: \n"); 
    /* Output the numbers in sorted order */
    for (int i = 0; i < numOfNum; i++)
    {
        printf("%d ", theNumbers[i]);
    }
    printf("\n");
    return 0; 
} 
