#include<bits/stdc++.h>
using namespace std;
void heapify_element(int arr[],int idx,int n)
{
     int largest=idx;
     int left=2*idx+1;
     int right=2*idx+2;
     if(left<n && arr[left]>arr[largest])
     largest=left;
     if(right<n && arr[right]>arr[largest])
     largest=right;

     if(largest!=idx)
     {
        int temp=arr[largest];
        arr[largest]=arr[idx];
        arr[idx]=temp;
        heapify_element(arr,largest,n);
     }
}
void heapify(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)
    {
        heapify_element(arr,i,n);
    }
}
void heapsort(int arr[],int n)
{
      heapify(arr,n);
      for(int i=n-1;i>=0;i--)
      {
          swap(arr[0],arr[i]);
         
          heapify_element(arr,0,i);    
      }
}
int main()
{
    int arr[]={1,4,2,6,5,3,7,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}