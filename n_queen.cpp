#include<bits/stdc++.h>
using namespace std;
#define N 8
#define M 8
class queen{
    bool visited[N][M];
    stack<pair<int,int>>st;
       public:
    queen()
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                visited[i][j]=0;
            }
        }
    }
    void explore(pair<int,int>p,int arr[N][M],int col)
    {
        int i=p.first;
        int j=p.second;
        int flag=0,flag2=0;
          //check for newxt row i+1 k
        for(int k=0;k<M;k++)
        { 
            flag=0;
            for(int u=0;u<=i;u++)
                if(visited[][u])
            if(flag==0)
            {
                st.push({i+1,k});
                flag2=1;
            }
        }
         // flag2=0;
            // if(k!=j && k!=j-1 && k!=j+1 )
            // {
            //      for(int w=0;w<=i;w++)
            //     {
            //         if(visited[w][k]==1 || (w-i==k-j) )
            //         {
            //               flag2=1;
            //               break;
            //         }
            //     }
            //     if(flag2!=1)
            //     {
            //              flag=1;
            //               st.push({i+1,k});
            //     }
                  
            // }
    }
    void place_queen(int arr[N][M])
    {
        int count;
       for(int col=0;col<M;col++)
       {
        count=0;
           st.push({0,col});
           pair<int,int> p;
           while(!st.empty())
           {
                  p=st.top();
                 st.pop();
                 for(int i=0;i<M;i++)
                  visited[p.first][i]=0;
                 visited[p.first][p.second]=1;
                 explore(p,arr,col);  
                 count++;   
           }
           if(p.first==N-1)
           {
              break;
           }
       }
    }

void display(int arr[N][M])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
}
};
int main(){
    int arr[N][M]={{0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   };
    queen q;
    q.place_queen(arr);
    q.display(arr);
}
