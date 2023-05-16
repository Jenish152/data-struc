#include<bits/stdc++.h>
using namespace std;
void makechange(int D[],int money_range,int D_size)
{
    
     int DP[D_size+1][money_range+1];
     for(int i=0;i<=D_size;i++)
     {
        for(int j=0;j<=money_range;j++)
        {
             if(i==0 || j==0)
             DP[i][j]=0;
             else if(i==1 && j>=D[i-1])
             {
                DP[i][j]=DP[i][j-D[i-1]]+1;
             }
             else if(j<D[i-1])
             {
                DP[i][j]=DP[i-1][j];
             }
             else
               DP[i][j]=min(DP[i-1][j],1+DP[i][j-D[i-1]]);
        }
     }
     int money;
     cout<<"enter money of you want change"<<endl;
     cin>>money;
     cout<<"total "<<DP[D_size][money]<<" minimum notes required"<<endl;

}
int main()
{
    int D[]={1,2,5,10,20,50,100,200,500,2000};
     int D_size=sizeof(D)/sizeof(D[0]);
    int money_range=1000;
    makechange(D,money_range,D_size);

}