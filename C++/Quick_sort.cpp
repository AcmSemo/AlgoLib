// Quick sort with O(nlogn) even in worst case...

#include <stdio.h>

// SWAP FUNCTION...
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

// FUNCTION TO FIND MEDIAN OF A SHORT(size<=5) ARRAY...
int findMedian(int b[], int n)
{
	int i,j,arr[n];
	for(i=0;i<n;i++)
		arr[i]=b[i];

	for(i=1;i<n;i++)
	{
		int j=i-1, temp=arr[i];
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
    return arr[n/2];
}

// FUNCTION TO IND MEDIAN OF A ARRAY  BY DIVIDING IN GROUP OF FIVE...
int medOfMed(int arr[], int low, int high)
{
	if(high-low<=1)
		return arr[low];

    int n = high-low+1;
    int i, median[(n+4)/5];
    
    for (i=0; i<n/5; i++)
        median[i] = findMedian(arr+low+i*5, 5);
    
    if (i*5 < n)
    {
        median[i] = findMedian(arr+low+i*5, n%5);
        i++;
    }

    return medOfMed(median,0,i-1);
}

// FUNCTION FOR PARTITION WITH MEDIAN AS PIVOT...
int partition (int arr[], int low, int high) 
{
	int i, temp = medOfMed(arr,low,high);
	
	for(i=low;i<=high;i++)
	{
		if(arr[i]==temp)
		{
			swap(&arr[i],&arr[high]);
			break;
		}
	}
    int pivot = arr[high];
    i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1);
}

// FUNCTION TO SORT...
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high);
  		quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    } 
}

// FUNCTION TO PRINT ELEMENTS OF A ARRAY...
void printArray(int arr[], int size) 
{ 
    int i; 
    
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    
    printf("\n"); 
}

// MAIN FUNCTION...
int main()
{
	int n,i;
	printf("Enter the number of elements in your array : ");
	scanf("%d",&n);
	
	printf("Enter the elements of your array one by one : \n");
	int a[n];
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	printf("Your Array : ");
	printArray(a,n);
	
	quickSort(a,0,n-1);
	
	printf("Sorted Array : ");
	printArray(a,n);
}
