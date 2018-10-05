// Made by Saurabh Bansal
// O(n log n) solution of Inversion Count problem using merge sort
// Problem statement :
// Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A.
// Given n and an array A your task is to find the number of inversions of A.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll merge(vector <int> &v, int l, int m, int r)
{
	vector <int> v1(m - l + 2), v2(r - m + 1);
	ll rv = 0;
	int n1 = m - l + 1, n2 = r - m, i1 = 0, i2 = 0;

	for (int i = 0; i < n1; i++)
	{
		v1[i] = v[l + i];
	}

	v1[n1] = INT_MAX;

	for (int j = 0; j < n2; j++)
	{
		v2[j] = v[m + 1 + j];
	}

	v2[n2] = INT_MAX;

	for (int i = l; i <= r; i++)
	{
		if (v1[i1] <= v2[i2])
		{
			v[i] = v1[i1];
			i1++;
		}

		else
		{
			rv += n1 - i1;
			v[i] = v2[i2];
			i2++;
		}
	}

	return rv;
}

ll mergesort(vector <int> &v, int l, int r)
{
	if (l == r)
		return 0;
	else
	{
		ll lans, rans, mrgans;
		int m = (l + r) / 2;
		lans = mergesort(v, l, m);
		rans = mergesort(v, m + 1, r);
		mrgans = merge(v, l, m, r);
		return (lans + rans + mrgans);
	}
}

int main()
{
	int n;
	cin >> n;// size of array
	vector <int> v(n); //array

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	cout <<"No. of inversions = "<< mergesort(v, 0, n - 1) <<"\n";
	return 0;
}