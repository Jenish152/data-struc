 #include<bits/stdc++.h>
using namespace std;
#define V 5
int selectMinnode(int weight[],bool visited[])
{
    int minn=INT_MAX;
     int vertex;
     for(int i=0;i<V;i++){
        if(visited[i]==0 && minn>weight[i])
         { vertex=i;
            minn=weight[i];}
     }
     return vertex;
}

void prim(int Graph[V][V])
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
         u=selectMinnode(weight,visited);
         visited[u]=1;
         for(int j=0;j<V;j++)
         {
            //there should be path between u & j
            //j should not be visited
            //length of  j is smaller than only update it with u,j.
            if(Graph[u][j]!=0 && visited[j]==0 && Graph[u][j]<weight[j])
            {
                weight[j]=Graph[u][j];
                parent[j]=u;
            }
         }

         
    }
    cout<<" msT :"<<endl;
    for(int i=1;i<V;i++)
    {
        cout<<i<<"---"<<parent[i]<<" => "<<weight[i]<<endl;
        ans+=weight[i];
    }
    cout<<"min weight of spanning tree: "<<ans<<endl;
}
int main()
{
     int Graph[V][V]={{0,2,0,3,5},
                      {2,0,6,1,0},
                      {0,6,0,4,0},
                      {3,1,4,3,0},
                      {5,0,0,0,0}};
    prim(Graph);
}