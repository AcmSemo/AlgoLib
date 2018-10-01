#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n), rank(n), U(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < n; i++)
        rank[i] = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j]>=a[i])
                rank[j]+=1;
            else
                rank[i]+=1;
        }
    }
    for(int i = 0; i < n; i++)
        U[rank[i] - 1] = a[i];
    for(int i = 0; i < n; i++)
        a[i] = U[i];
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
}