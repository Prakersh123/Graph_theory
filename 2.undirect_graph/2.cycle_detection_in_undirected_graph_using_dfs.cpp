#include<bits/stdc++.h>
using namespace std;

 bool   dfs(vector<int> adj[],bool visited[],int s,int parent)
{
    visited[s]=true;

    for(auto u: adj[s])
    {
        if(visited[u]==true && u!=parent)
        return true;
        else if (visited[u]==false)
        { if(!dfs(adj,visited,u,s))
         continue;
         else 
         {
             return true;
         }
        }
    }
    return false;
    
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
        adj[v].push_back(u);
    }

    bool visited[n]={false};

    for(int i=0;i<n;++i)
        {
    if(visited[i]==false)
    {
        cout<<dfs(adj,visited,i,-1)<<endl;;
    }
    }

}