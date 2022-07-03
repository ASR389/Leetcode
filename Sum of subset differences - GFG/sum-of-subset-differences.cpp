// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std;

int sumDiff(int S[], int n);

 
// Driver program to test above function
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int S[n];
   	for(int i=0;i<n;i++)
   	cin>>S[i];
    cout<<sumDiff(S, n)<<endl;;
   }
  
    return 0;
}// } Driver Code Ends

// Returns the sum of first elements of all subsets
int SumF(int S[], int n)
{
    int sum = 0;
  
    // Compute the SumF as given in the above explanation
    for (int i = 0; i < n; i++)
        sum = sum + (S[i] * pow(2, n-i-1));
    return sum;
}
  
// Returns the sum of last elements of all subsets
int SumL(int S[], int n)
{
    int sum = 0;
  
    // Compute the SumL as given in the above explanation
    for (int i = 0; i < n; i++)
        sum = sum + (S[i] * pow(2, i));
    return sum;
}
  
// Returns the difference between sum of last elements of
// each subset and the sum of first elements of each subset
int sumSetDiff(int S[], int n)
{
    return SumL(S, n) - SumF(S, n);
}
/*You are required to complete this method */
int sumDiff(int S[], int n)
{
    return sumSetDiff(S,n);
}