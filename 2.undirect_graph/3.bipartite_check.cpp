/*
Bipartite Graph:  A graph where you can divide all vertices into two set, such that all edges of the graph
                  are between set 1 and set 2 only. 
    
    (1): If your graph contains a cycle with odd length then it's non bipartite.

    (2): Using bfs/dfs color the graph using two colors only . If you will be successfull to color each node such that
        no two adjacent nodes have same color , then your graph is bipartite else it is non bipartite.

*/

#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<int> adj[],bool visited[],int s,int color[])
{
    visited[s]=true;
    color[s]=0;
    queue<int> q;
    q.push(s);
    while(q.empty()==false)
    {
        int u = q.front();
        q.pop();
        for(auto v: adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
                color[v]=1-color[u];

            }
            else if(color[v]==color[u])
            return false;
        }
    }
    return true;
}

bool dfs(vector<int> adj[],bool visited[],int color[],int s,int col)
{
    visited[s]=true;
    color[s]=col;
    
        for(auto v: adj[s])
        {
            if(visited[v]==false)
            {
                if(dfs(adj,visited,color,v,1-col));
                else 
                return false;
            }
            else if(color[v]==color[s])
            return false;
        }
        return true;
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
    bool print= false;
    bool visited[n]={false};
    int color[n]={-1};
    for(int i =0;i<n;i++)
    {
        if(visited[i]==false)
        {
        //    if( bfs(adj,visited,i,color));
            if(dfs(adj,visited,color,i,0));
           else 
           {
               cout<<"Non bipartite";
               print=true;
               break;
           }
        }
    }

    if(print==false)
    cout<<"Bipartite"<<endl;


    return 0;
}