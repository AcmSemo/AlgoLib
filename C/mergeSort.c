//Merge Sort

#include <stdio.h>

void merge(int arr[] , int left , int mid , int right)
{
    int i , j , k;
    int n1 = mid-left+1;
    int n2 = right - mid;
    int l1[n1] , l2[n2];

    for(i = 0 ; i < n1 ; i++){
        l1[i] = arr[left+i];
    }

    for(j = 0 ; j < n2 ; j++){
        l2[j] = arr[mid+1+j];
    }

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2){
        if(l1[i] > l2[j]){
            arr[k] = l2[j];
            j++;
        } else {
            arr[k] = l1[i];
            i++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = l1[i];
        i++;
        k++;

    }

    while(j < n2){
        arr[k] = l2[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[] , int l , int r){

    if(l < r){
        int m = (l+r)/2;
        mergeSort(arr , l , m);
        mergeSort(arr , m+1 , r);
        merge(arr , l , m , r);
    }

}

int main(){

    int arr[] = {5,2,4,8,9,1,3,10,6,7};
    int size = sizeof(arr)/ sizeof(arr[0]);
    mergeSort(arr , 0 , size-1);
    for(int i = 0 ; i < size ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
