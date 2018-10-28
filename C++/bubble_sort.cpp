#include <iostream>
using namespace std;

void b_sort(int n, int a[]);

int main()
{
  int a[100], n;

  cout << "Enter the number of elements to be inserted: ";
  cin >> n;

  cout << "Enter the elements: \n";
  for(int i=0; i<n; i++)
  {
    cin >> a[i];
  }

  b_sort(n, a);

  cout << "SORTED ARRAY: \n";
  for(int i=0; i<n; i++)
  {
    cout << a[i] << " ";
  }

  return 0;
}

void b_sort(int n, int a[])
{
  int temp;

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n-1-i; j++)
    {
      if(a[j] > a[j+1])
      {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}
