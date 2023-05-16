#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n)
{
    
   for(int i=1;i<n;i++)
   {
       int j=i-1;
       int key=arr[i];
       while(j>=0 && arr[j]>key)
       {
          arr[j+1]=arr[j];
          j--;
       }
       arr[j+1]=key;
       
   }
}
int main()
{
   int arr[]={5,3,4,6,1,2};
   int n=sizeof(arr)/sizeof(arr[0]);
   insertion_sort(arr,n);
   for(int i=0;i<n;i++)
   {
      cout<<arr[i]<<" ";
   }
}