#include<bits/stdc++.h>
using namespace std;
void count_sort(int arr[],int n)
{
    int mx=arr[0];
    for(int i=0;i<n;i++)
    mx=max(mx,arr[i]);
    int *count;
    count=new int[mx+1];
    for(int i=0;i<=mx;i++)
      count[i]=0; 

    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i=1;i<=mx;i++)
    {
        count[i]+=count[i-1];
    }
    
    int ans[n];
    
    for(int i=n-1;i>=0;i--)
    {
       
        ans[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=ans[i];
    }
}
int main()
{
    int arr[]={1,4,5,5,3,2,6};
    count_sort(arr,7);
    for(int i=0;i<7;i++)
    cout<<arr[i]<<" ";
}