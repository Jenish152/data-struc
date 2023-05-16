#include<bits/stdc++.h>
using namespace std;
//bfs from adjacencey matrix
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
    queue<int> q;
    bool visited[n];

    q.push(0);
    visited[0] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<endl;

        for(int i=0;i<n;i++){
            if(adjm[node][i]==1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return 0;
}