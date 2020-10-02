#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int a,b;
	cin>>a>>b;
	int result = (a>b)?gcd(a,b):gcd(b,a);
	cout<<result<<endl;
	
	return 0;
}
