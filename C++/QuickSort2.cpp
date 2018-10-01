// Quick Sort

#include <bits/stdc++.h>

using namespace std;

void swap(int *a , int *b){
    int t = *b;
    *b = *a;
    *a = t;
}


int partition(int arr[] , int start , int end){

    int pivot = arr[end];
    int pIndex = start;

    for(int i = pIndex ; i <= end-1 ; i++){
        if(arr[i] < pivot){
            swap(&arr[i] , &arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[pIndex] , &arr[end]);
    return pIndex;
}


void quickSort(int arr[] , int start , int end) {
    if (start < end) {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

int main(){

    //int arr[] = {10, 7, 8, 9, 1, 5};
    int arr[] = { 12 , 4 ,6, 5 , 10 , 11  ,2 };
    int n = sizeof(arr)/ sizeof(arr[0]);
    quickSort(arr , 0 , n-1);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}

