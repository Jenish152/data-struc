#include<iostream>
using namespace std;
int find_pivot(int arr[],int l,int h)
{
    int pivot=l;
    int i=l+1,j=h;
    while(i<j)
    {
       while(arr[i]<arr[pivot])
      {
         i++;
      }
      while(arr[pivot]<arr[j])
      {
         j--;
      }
      cout<<i<<" "<<j<<endl;
      if(i<j)
      {
         int temp=arr[i];
         arr[i]=arr[j];
         arr[j]=temp;
      }
      
    }
    int temp=arr[j];
    arr[j]=arr[pivot];
    arr[pivot]=temp;
   
    return j;    
}
void quicksort(int arr[],int l,int h)
{
    int pivot;
    if(l<h)
    {
        pivot=find_pivot(arr,l,h);
        quicksort(arr,l,pivot-1);
        quicksort(arr,pivot+1,h);
    }
}
int main()
{
    int arr[]={4,2,6,1,3,6,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int start=0;
    int end=size-1;
    quicksort(arr,start,end);
    for(int i=0;i<size;i++)
     cout<<arr[i]<<" ";
}