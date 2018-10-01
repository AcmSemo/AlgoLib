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
    int p_index = start;

    for(int i = p_index ; i <= end-1 ; i++){
        if(arr[i] < pivot){
            swap(&arr[i] , &arr[p_index]);
            p_index++;
        }
    }
    swap(&arr[p_index] , &arr[end]);
    return p_index;
}


void quick_sort(int arr[] , int start , int end) {
    if (start < end) {
        int p = partition(arr, start, end);
        quick_sort(arr, start, p - 1);
        quick_sort(arr, p + 1, end);
    }
}

int main(){

    //int arr[] = {10, 7, 8, 9, 1, 5};
    int arr[] = { 12 , 4 ,6, 5 , 10 , 11  ,2 };
    int n = sizeof(arr)/ sizeof(arr[0]);
    quick_sort(arr , 0 , n-1);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}


