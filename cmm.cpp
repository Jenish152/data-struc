#include<bits/stdc++.h>
using namespace std;
class cmm{
    int DP[100][100];
    public:
    cmm()
    {
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            DP[i][j]=-1;
        }
    }
    int matrixchain(int arr[],int i,int j)
    {
        //if both matrix are same,then 0 multiplication possible.
        if(i==j)
        return 0;

        //if multiplications already counted,then no noeed to count.
        if(DP[i][j]!=-1)
        return DP[i][j];

        DP[i][j]=INT_MAX;
        //find minimum among all partitions,and find minimum  multiplications possible.
        for(int k=i;k<j;k++)
        {
            if(DP[i][j]>(matrixchain(arr,i,k)+matrixchain(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]))
            {
                DP[i][j]=matrixchain(arr,i,k)+matrixchain(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            }
        }
        
        return DP[i][j];
    }
};
int main()
{
    int arr[]={1,2,3,4,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cmm obj;
    cout<<obj.matrixchain(arr,1,n-1)<<endl;
}