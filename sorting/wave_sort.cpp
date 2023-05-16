#include<bits/stdc++.h>
using namespace std;
void wave(int arr[],int n)
{
    for(int i=1;i<n;i+=2)
    {
        if(arr[i]>arr[i-1])
        {
            swap(arr[i],arr[i-1]);
        }
        if(arr[i]>arr[i+1] && i+1<n)
        {
            swap(arr[i],arr[i+1]);
        }
    }
}
int main()
{
    int arr[]={1,4,5,3,2,7};
    wave(arr,6);
    for(int i=0;i<6;i++)
    cout<<arr[i]<<" ";
}