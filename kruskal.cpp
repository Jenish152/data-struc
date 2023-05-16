#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int *parent;
    int V;
    int E;

public:
    Graph(int v, int e)
    {
        V = v;
        E = e;
        parent = new int[V];
        for(int i=0;i<V;i++)
        parent[i]=-1;
    }
    int find(int node)
    {
        if (parent[node] == -1)
            return node;
        return find(parent[node]);
    }
    void unionn(int u, int w)
    {
        parent[u] = w;
    }

    bool detectcycle(pair<pair<int, int>,int> p)
    {
        int u, w;
            u = find(p.first.first);
            w = find(p.first.second);
            if (u == w)
                return 1;
            unionn(u, w);
        return 0;
    }
    bool compare_value( int a,int b)
    {
        return a > b;
    }
    void kruskal(vector<pair<pair<int, int>,int>> edges)
    {
        vector<pair<pair<int, int>,int>>msT;
       for(int i=0;i<E-1;i++)
       {
        for(int j=0;j<E;j++)
        {
            if(compare_value(edges[j].second,edges[j+1].second))
            {
                 pair<pair<int, int>,int>temp=edges[j];
                 edges[j]=edges[j+1];
                 edges[j+1]=temp;
            }
        }
       }
        int count=0;
        for(int i=0;count!=V-1;i++)
        {
            if(!detectcycle(edges[i]))  //if there is no cycle
            {
                 msT.push_back(edges[i]);
                 count++;
            }
        }
        int sum=0;
        for(int i=0;i<V-1;i++)
        {
            cout<<msT[i].first.first<<"--"<<msT[i].first.second<<" ------> "<<msT[i].second<<endl;
            sum+=msT[i].second;
        }
        cout<<"min cost: "<<sum<<endl;
    }

};
int main()
{
    int V, E;
    cin >> V >> E;
    int from, to,value;
    vector<pair<pair<int, int>,int>> edges;
    for (int i = 0; i < E; i++)
    {
        cout << "Edge " << i + 1 << " : ";
        cin >> from >> to >> value;
        //edges.push_back(make_pair(make_pair(from, to),value));
        edges.push_back({{from,to},value});
    }
    Graph G(V,E);
    G.kruskal(edges);
}