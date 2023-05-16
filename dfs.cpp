#include<bits/stdc++.h>
using namespace std;
void dfsForMatrix(bool visited[], vector<vector<int>> adjm,int node,int n){
    cout<<node<<endl;
    visited[node] = true;
    for(int i=0;i<n;i++){
        if(adjm[node][i] == 1 && !visited[i]){
            dfsForMatrix(visited, adjm, i, n);
        }
    }
}
void dfsForList(bool visited[], vector<int> adjl[], int node, int n){
    cout<<node<<endl;
    visited[node] = true;
    vector<int> :: iterator it;
    for(it = adjl[node].begin();it!= adjl[node].end();it++){
        if(!visited[*it]){
            dfsForList(visited, adjl,*it, n);
        }
    }
}
int main(){
    int n,m; //n->number of nodes   m->no of edges (a->b)
    cin>>n>>m;
    vector<vector<int>> adjm(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }
    cout<<"Adjacency matrix of input graph is : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adjm[i][j]<<" ";
        }
        cout<<endl;
    }

    bool visited1[n];
    dfsForMatrix(visited1, adjm, 0, n);

    cin>>n>>m;
    vector<int> adjl[n];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adjl[x].push_back(y); 
        adjl[y].push_back(x); 
    }

    cout<<"Adjacency list of input graph is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" -> ";
        vector<int> :: iterator it;
        for(it = adjl[i].begin();it!=adjl[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    bool visited2[n];
    dfsForList(visited2, adjl, 0, n);
    return 0;
}