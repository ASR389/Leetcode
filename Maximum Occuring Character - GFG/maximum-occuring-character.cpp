// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
 char getMaxOccuringChar(string str)
   {
       // Your code here
       int res,max_val=0;
       int count[26]={0};
       for(int i=0;i<str.length();i++)
       {
           count[str[i]-'a']++;
       }
       for(int i=0;i<26;i++)
       {
           if(count[i]>max_val)
           {
               res=i;
               max_val=count[i];
           }
       }
       return res+'a';
       
   }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends