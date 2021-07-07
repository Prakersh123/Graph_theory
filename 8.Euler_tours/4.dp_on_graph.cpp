#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[],bool visited[],int s,int parent,int count,int dp[],int level[])
{
    visited[s]=true;
    dp[s]=count;
    level[s]=count;
    for(auto u: adj[s])
    {
        if(visited[u]==false)
        {
            dfs(adj,visited,u,s,count+1,dp,level);
            dp[s]=min(dp[s],dp[u]);
        }
        else if(u!=parent)
        {
            dp[s]=min(dp[s],level[u]);
        }
        // dp[s]=min(dp[s],dp[])
    }
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
        adj[v].push_back(u);
    }
    bool visited[n];
    int dp[n];
    int level[n];
    fill(visited,visited+n,false);
    dfs(adj,visited,0,-1,0,dp,level);
    for(int i=0;i<n;i++)
    cout<<i<<"-->"<<dp[i]<<endl;


}