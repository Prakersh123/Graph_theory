#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],bool visited[],int s , queue<int> &q,int indegree[])
{

    while(q.empty()==false)
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v: adj[u])
        {
            if(indegree[v]!=0)
            {
                indegree[v]--;
                if(indegree[v]==0)
                q.push(v);
            }
        }
    }

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
    int indegree[n]={0};
    for(int i=0;i<e;++i)
    {   int u,v; 
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
        indegree[v]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(!indegree[i])
        q.push(i);
    }

    bool visited[n]={false};

   
        bfs(adj,visited,0,q,indegree);
    
}