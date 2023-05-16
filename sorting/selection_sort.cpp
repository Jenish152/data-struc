#include<iostream>
using namespace std;
void selection_sort(int arr[],int n)
{
    int min,index;
     for(int i=0;i<n-1;i++)
     {
        min=arr[i];
        index=i;
        for(int j=i+1;j<n;j++)
        {
            if(min>arr[j])
            {
               min=arr[j];
               index=j;
            }
        }
        int temp=arr[i];
        arr[i]=min;
        arr[index]=temp;
     }
}
int main(){
   int arr[]={1,4,2,5,6,3};
   int n=sizeof(arr)/sizeof(arr[0]);
   selection_sort(arr,n);
   for(int i=0;i<n;i++)
   {
    cout<<arr[i]<<" ";
   }
}