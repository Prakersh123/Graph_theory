#include<bits/stdc++.h>
using namespace std;

void calculate_smallest(vector<int> adj[],bool visited[],int s,int dp[])
{
    visited[s]=true;
    for(auto u: adj[s])
    {
        if(visited[u]==false)
        {
            calculate_smallest(adj,visited,u,dp);
            dp[s]=min(dp[s],dp[u]);

        }

    }
    // dp[s]=min(s,dp[s]);
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
    int dp[n];
    fill(dp,dp+n,INT_MAX);
bool visited[n];
fill(visited,visited+n,false);
    for(int i=0;i<n;i++)
    dp[i]=i;
   
    calculate_smallest(adj,visited,0,dp);
   
   
    for(int i=0;i<n;i++)
    cout<<dp[i]<<" ";
    return 0;
}