#include<stdio.h>
void heapify(int arr[],int n,int i){
	int root,left,right,tmp;
	root = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if(left < n && arr[left] > arr[root])
		root = left;
	if(right < n && arr[right] > arr[root])
		root = right;
		
	if(root != i){
		tmp = arr[root];
		arr[root] = arr[i];
		arr[i] = tmp;
		heapify(arr,n,root);
	}
} 
void heapsort(int arr[],int n){
	int i,tmp;
	for(i = (n/2 - 1); i >= 0; i--){
		heapify(arr,n,i);
	}
	for(i = n-1; i >= 0; i--){
		tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		heapify(arr,i,0);
	}
}
int main(){
    
	int i,n;
	printf("Enter number elements to be sorted:" );
    scanf("%d",&n);
    int arr[n];
	for(i = 0; i < 5; i++)
		scanf("%d",&arr[i]);
	heapsort(arr,n);
	for(i = 0; i < n; i++) 
		printf("%d ",arr[i]);
return 0;
}
