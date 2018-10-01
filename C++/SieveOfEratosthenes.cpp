#include<iostream>
using namespace std;

// initialize array
void init(bool arr[], int n)
{
    // 0 & 1 is not prime number
    arr[0] = false;
    arr[1] = false;
	for(int i=2; i<=n; i++){
        arr[i] = true;
	}
}

// After finish this function, each index in array that has true as value is a prime number
void prime_sieve(bool arr[], int n){
    // first round filter by 2
    for(int j = 4; j <= n; j+=2){
        // j is not a prime number because it is divided by 2
        arr[j] = false;
    }
    // next we do this for all other odd number
    for(int i = 3; i <= n; i+=2){
        // if value of index i is already false then it is not a prime number
        if(arr[i] == false) continue;
        for(int j = i+i; j <= n; j+=i){
            // j is not a prime number because it is divided by i
            arr[j] = false;
        }
    }
}

int main()
{
	bool arr[31];
	int n = 30;

	init(arr, n);

    prime_sieve(arr, n);

	cout<<"Prime number from 1-30: "<<endl;
	for(int i=1; i<=n; i++)
		if(arr[i] == true)
            cout<< i << " ";

	cout<<endl;

	return 0;
}

