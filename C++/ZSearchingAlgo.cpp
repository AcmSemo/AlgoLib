#include<iostream>
using namespace std;

#Algorithm is similar to KMP but easier to implement

void getZarr(string str, int Z[]);  
void search(string text, string pattern) 
{ 
     
    string concat = pattern + "$" + text; 
    int l = concat.length(); 
   
    int Z[l]; 
    getZarr(concat, Z); 
   
    for (int i = 0; i < l; ++i) 
    { 
        if (Z[i] == pattern.length()) 
            cout << "Pattern found at "
                << i - pattern.length() -1 << endl; 
    } 
} 
  
void getZarr(string str, int Z[]) 
{ 
    int n = str.length(); 
    int L, R, k;  
    L = R = 0; 
    for (int i = 1; i < n; ++i) 
    { 
        if (i > R) 
        { 
            L = R = i; 
            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else
        { 
            k = i-L; 
            if (Z[k] < R-i+1) 
                Z[i] = Z[k]; 

            else
            {  
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
        } 
    } 
}  
int main() 
{ 
    string text = "HERCULES IS HERCULES IS HERCULES"; 
    string pattern = "HERCULES"; 
    search(text, pattern); 
    return 0; 
} 