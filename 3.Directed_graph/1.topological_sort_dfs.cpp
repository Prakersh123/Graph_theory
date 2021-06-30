#include<bits/stdc++.h>
using namespace std;


void depth_first_search(vector<int> adj[],bool visited[],int s,stack<int> &q)
{
    visited[s]=true;
    for(auto u: adj[s])
    {
        if(visited[u]==false)
        depth_first_search(adj,visited,u,q);
    }
    q.push(s);
}



int main()
{
     //number of nodes
    int n;
    cin>>n;
    //number of edges
    int e;
    cin>>e;
    
    //adjecency list
    //space comp: O(n+2e)
    vector<int> adj[n];
    for(int i=0;i<e;++i)
    {   int u,v; 
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    bool visited[n]={false};
    stack<int> q;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        depth_first_search(adj,visited,i,q);
    }
    while(q.empty()==false)
    {
        cout<<q.top()<<" ";
        q.pop();
    }
}