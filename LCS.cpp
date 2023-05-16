
#include<bits/stdc++.h>
using namespace std;
void LCS1(string s1,string s2)
{
    int m=s1.length();
    int n=s2.length();
    int arr[m+1][n+1];
    for(int i=0;i<=n;i++)
    arr[0][i]=0;
    for(int i=0;i<=m;i++)
    arr[i][0]=0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                arr[i][j]=1+arr[i-1][j-1];
            }
            else{
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    string ans="";
    int i=m,j=n;
        while(j!=0 && i!=0)
        {
            if(s1[i-1]==s2[j-1])
           {
              ans+=s1[i-1];
              i--;j--;  
           }
           else
           {
               if(arr[i-1][j]>arr[i][j-1])
               i--;
               else
               j--;
           }
        }
        reverse(ans.begin(), ans.end());
        cout<<"substring with maximum length: "<<ans<<endl;
        cout<<"max. length: "<<arr[m][n]<<endl;
}

int main()
{
    string s1="ABCBDA";
    string s2="BDCABA";
    LCS1(s1,s2); ////longest common subsequence
}