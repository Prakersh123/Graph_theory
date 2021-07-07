#include <bits/stdc++.h>
using namespace std;


//1. dfs tree
//2. discovery time
//3.lowest time
vector<int> articulation;
vector<int> bridge;

void dfs(vector<int> adj[],bool visited[],int s, int parent,int & count,int dp[],int time[])
{
    visited[s]=true;
    time[s]=count;
    dp[s]=count;
    int child=0;
    for(auto u: adj[s])
    {
        if(visited[u]==false)
        {
            count++;
            dfs(adj,visited,u,s,count,dp,time);
            dp[s]=min(dp[s],dp[u]);
            child++;
        }
        else if(parent!=u)
        {
            dp[s]=min(dp[s],time[u]);
        }
    }
    if(s!=0)
    for(auto u: adj[s])
    {
        if(dp[u]>=time[s])
        {
            articulation.push_back(s);
            break;
        }
        if(dp[u]>time[s])
        {
            bridge.push_back(s);
            break;
        }
    }
    if(s==0 and child>=2)
    {
        articulation.push_back(0);
    
    }
}

int main()
{
    int n;
    cin>>n;
    int e;
    cin>>e;

    vector<int>  adj[n];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool visited[n];
    fill(visited,visited+n,false);
    int dp[n],time[n];
    int count=0;
    dfs(adj,visited,0,-1,count,dp,time);
    for(auto x: articulation)
    cout<<x<<" ";
    cout<<endl;
    cout<<"bridges-->";
    for(auto x: bridge)
    cout<<x<<" ";
    return 0;
}