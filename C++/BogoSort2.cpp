#include<iostream>
#include <algorithm>
using namespace std;

// check whether array is sorted
bool is_array_sorted(int arr[], int n){
    for(int i=0; i < n-1; i++){
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}

void bogo_sort(int arr[], int n){
    // Shuffle until array is sorted
    while(!is_array_sorted(arr, n)){
        random_shuffle(arr, arr+n);
    }
}

int main()
{
    int arr[] = {1, 5, 2, 4, 10, 8, 7, 9, 3, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    bogo_sort(arr, n);

	cout<<"sorted array : "<<endl;
	for(int i=0; i<n; i++)
        cout<< arr[i] << " ";

	cout<<endl;

	return 0;
}

