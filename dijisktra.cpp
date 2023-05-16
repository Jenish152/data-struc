#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int selectMinnode(int weight[],bool visited[],int V)
{
    int minn=INT_MAX;
     int vertex;
     for(int i=0;i<V;i++){
        if(visited[i]==0 && minn>=weight[i])
         { vertex=i;
            minn=weight[i];}
     }
     return vertex;
}

void dijkastra(int Adj[9][9],int V)
{ 
    int ans=0;
    int parent[V];  //parent array (which node is connect to which in spanning tree)
    int weight[V];
    for(int i=0;i<V;i++)
     weight[i]=INT_MAX;  //set infinity weight of all node
    bool visited[V];
    for(int i=0;i<V;i++)
     visited[i]=0;  //those node enters in spanning tree,mark as true.

    //intialization
    parent[0]=-1;
    weight[0]=0;
    int u;
    //v-1 edges
    for(int i=0;i<V-1;i++)
    {
         u=selectMinnode(weight,visited,V);
         visited[u]=1;
         for(int j=0;j<V;j++)
         {
            if(Adj[u][j]!=0 && visited[j]==0 && visited[u]!=INT_MAX && Adj[u][j]+weight[u]<weight[j])
            {
                weight[j]=Adj[u][j]+weight[u];
                parent[j]=u;
            }
         }
    }
    cout<<"for 0:"<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<i<<") "<<weight[i]<<endl;
    }
}
int main()
{
    int V=9;
    int Adj[9][9]={{0,4,0,0,0,0,0,8,0},
                   {4,0,8,0,0,0,0,11,0},
                   {0,8,0,7,0,4,0,0,2},
                   {0,0,7,0,9,14,0,0,0},
                   {0,0,0,9,0,10,0,0,0},
                   {0,0,4,14,10,0,2,0,0},
                   {0,0,0,9,0,2,0,1,6},
                   {8,11,0,9,0,0,1,0,7},
                   {0,0,2,0,0,0,6,7,0}};
    dijkastra(Adj,V);
}