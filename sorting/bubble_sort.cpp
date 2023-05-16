#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n)
{
    int temp,flag;
     for(int i=0;i<n-1;i++)
     {
        flag=0;
        for(int j=0;j<n;j++)
        {
             if(arr[j]>arr[j+1])
             {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
             }
        }
        if(flag==0)
        {
           return;
        }
     }
}
int main(){
   int arr[]={1,2,3,4,5,6};
   int n=sizeof(arr)/sizeof(arr[0]);
   bubble_sort(arr,n);
   for(int i=0;i<n;i++)
   {
      cout<<arr[i]<<" ";
   }
}