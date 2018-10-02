#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int left[n1],right[n2];
	for (i=0;i<n1;i++)
		left[i]=arr[l+i];
	for (j=0;j<n2;j++)
		right[j]=arr[m+1+j];
	i=0;j=0;k=l;
	while (i<n1 && j<n2)
	{
		if (left[i]<=right[j])
			arr[k]=left[i++];
		else
			arr[k]=right[j++];
		k++;
	}
	while (i<n1)
	{
		arr[k]=left[i++];
		k++;
	}		
	while (j<n2)
	{
		arr[k]=right[j++];
		k++;
	}	
}

void mergesort(int arr[], int l, int r)
{
	if (l<r)
	{
		int m=l+(r-l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);		
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	mergesort(arr,0,n-1);
	printf("The sorted array is:\n");
	for (i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
