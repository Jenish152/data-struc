#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r)
{
    int n1=mid+1-l;
    int n2=r-mid;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[i+l];
    }
    for(int j=0;j<n2;j++)
    {
        b[j]=arr[j+mid+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {    
        if(a[i]<=b[j])
        arr[k++]=a[i++];
        else
        arr[k++]=b[j++];
    }
    while(i<n1)
    {
        arr[k++]=a[i++];
    }
    while(j<n2)
    {
        arr[k++]=b[j++];
    }
}
void mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main()
{
    int arr[]={4,2,6,1,3,6,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int l=0;
    int r=size-1;
    mergesort(arr,l,r);
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" "; 
}