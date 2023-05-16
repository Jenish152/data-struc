#include<bits/stdc++.h>
using namespace std;
#define N 5
#define M 5
class rat{
    bool visited[N][M];
    int ans[N][M];
    stack<pair<int,int>>st;
       public:
    rat()
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                visited[i][j]=0;
                ans[i][j]=0;
            }
        }
    }
void explore(pair<int,int> p,int arr[N][M])
{
    int i=p.first;
    int j=p.second;
    int flag=0;
    if(i-1>=0 && visited[i-1][j]!=1 && arr[i-1][j]==1)
    {
        st.push({i-1,j});
        visited[i-1][j]=1;
        flag=1;
    }
    if(i+1<N && visited[i+1][j]==0 && arr[i+1][j]==1)
    {
        st.push({i+1,j});
        visited[i+1][j]=1;
        flag=1;
    }
    if(j-1>=0 && visited[i][j-1]==0 && arr[i][j-1]==1)
    {
        st.push({i,j-1});
        visited[i][j-1]=1;
        flag=1;
    }
     if(j+1<M && visited[i][j+1]==0 && arr[i][j+1]==1)
    {
        st.push({i,j+1});
        visited[i][j+1]=1;
        flag=1;
    }
    if(flag==0)
    arr[i][j]=0;  
}
bool rate_maze(int first,int second,int fx,int fy,int arr[N][M])
{
    if(arr[first][second] !=1)
    return 0;
     st.push({first,second});
     visited[first][second] =1;
     while(!st.empty())
     {
         pair<int,int> p=st.top();
         if(p.first==fx && p.second==fy)
         {
            return true;
         }
         st.pop();
         explore(p,arr);  
     }
     return false;
     
}
void display(int arr[N][M])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
};
int main(){
    int arr[N][M]={{1,1,1,1,1},
                   {0,0,0,1,0},
                   {0,1,1,1,0},
                   {0,1,0,0,0},
                   {0,1,1,1,1}};
                   int i=2,j=1; //start
                   int p=4,q=4; //end
    rat r;
    if(r.rate_maze(i,j,p,q,arr))
    {
        cout<<"path exist"<<endl;
    }
    else
    {
        cout<<"path not exist"<<endl;
    }
    r.display(arr);
}
