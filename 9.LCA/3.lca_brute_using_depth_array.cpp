#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[],bool visited[],int s,int depth[],int par[])
{
    visited[s]=true;
    for(auto u: adj[s])
    {
        if(visited[u]==false)
        {
            par[u]=s;
            depth[u]=depth[s]+1;
            dfs(adj,visited,u,depth,par);
        }
    }
}

int lca_brute(int x,int y,int depth[],int par[])
{
    if(x==y) return x+1;
    
    //assuming that x is always at lower depth 
    if(depth[x]<depth[y])
    swap(x,y);
    while(depth[x]>depth[y])
    {
        x=par[x];
    }
    while(x!=y)
    {
        x=par[x];
        y=par[y];
    }
    return x+1;
}

int main()
{
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<int> adj[n];

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    int depth[n];
    depth[0]=0;
    int par[n];
    par[0]=-1;
    bool visited[n];
    fill(visited,visited+n,false);
    dfs(adj,visited,0,depth,par);
    int x,y;
    cin>>x>>y;
    x--;y--;
    cout<<lca_brute(x,y,depth,par)<<endl;   
}