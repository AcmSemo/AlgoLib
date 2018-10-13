// This Algorithm is used to sort elements ranging 0 to 1(not included) 

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std; 

void bsort(float array[], int n) 
{ 
	// making an array of vectors of size n
	vector<float> vec[n];
	for(int i=0;i<n;i++){
		int index_;
		// index value lies between 0 to n(not included)
		// because a[i] lies between 0 to 1(not included)
		index=n*array[i];
		// pushing the element in the bucket(vector) of index index_ 
		vec[index_].push_back(array[i]);
	}
	for(int i=0;i<n;i++){
		// sorting each bucket of index i
		sort(vec[i].begin(),vec[i].end());
	}
	int index=0;
	// now merging all the bucket elements in the previous array
	for(int i=0;i<n;i++)
		for(int j=0;j<vec[i].size();j++)
			array[index++]=vec[i][j];
} 
  
int main() 
{ 
    int n;
    // n is the no. of elements to be sorted
    cin>>n;
    float array[n];
    // storing elements in array
    for(int i=0;i<n;i++){
    	cin>>array[i];
    }
    bsort(array, n); 
  // output the sorted array
    for(int i=0;i<n;i++)
    	cout<<array[i]<<" ";
    cout<<endl;
    return 0; 
} 