/* Rank Sort implementation in C
 * Author : Manvi Gupta
 * Input : Array length and elements
 * Output : Sorted array elements
 */

#include <stdio.h>

int n;
void RankSort(int A[])
{
	int r[n];
	for(int i=0;i<n;i++)
		r[i]=0;

	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
	  	if(A[i]<A[j])
	  		r[j]++;
	  	else
	  		r[i]++;
	int u[n];
	for(int i=0;i<n;i++)
	  u[r[i]] = A[i];
	for(int i=0;i<n;i++)
	  A[i] = u[i];
}

int main()
{
  scanf("%d", &n);
	int a[n];
	for(int i=0;i<n;i++)
	scanf("%d", &a[i]);
	RankSort(a);
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
	return 0;
}
