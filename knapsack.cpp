#include<iostream>
#include<cmath>
using namespace std;

int knapsack(int v[],int w[],int capacity,int n)
{
    if(n==0 || capacity==0)
    return 0;

    if(w[n-1]>capacity) //if our capacity is smaller than picking an item of particular weight,then profit is 
    //equal to profit for same capacity with 1 less item avilable in stock as its weight is small.
    {
         return knapsack(v,w,capacity,n-1);
    }
    return (max(knapsack(v,w,capacity,n-1),knapsack(v,w,capacity-w[n-1],n-1)+v[n-1]));
    //return max of 1 less avilable item(no picking item) & picking item
}

int main()
{
    int v[5]={1,6,18,22,28}; //value
    int w[5]={1,2,5,6,7}; //weight
    int capacity;
    int size=sizeof(v)/sizeof(v[0]);
    //for creating 2d array of profits for different no. of items avilable and for different capacity.
    int V[size+1][10+1];
    for(int i=0;i<=size;i++)
    {
        
        for(int j=0;j<=10;j++)
        {
           V[i][j]=knapsack(v,w,j,i);
        }
    }
    for(int i=0;i<=size;i++)
    {
        for(int j=0;j<=10;j++)
         cout<<V[i][j]<<" ";
         cout<<endl;
    }
    int item;
    cout<<"enter your capacity & items avilable:"<<endl;
    cin>>capacity>>item;
    cout<<"max profit:"<<V[item][capacity];
    
}