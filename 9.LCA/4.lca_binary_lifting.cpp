#include<bits/stdc++.h>
using namespace std;
const int N=100005, k=22;

void dfs(vector<int> adj[],bool visited[],int s,int depth[])
{
    visited[s]=true;
    for(auto u: adj[s])
    {
        if(visited[u]==false)
        {
            depth[u]=depth[s]+1;
            dfs(adj,visited,u,depth);
        }
    }
}
// int sp_table[N][k];

void sparse_table(vector<int> adj[],bool visited[],int s,int par,vector<vector<int>> &sp_table,int n,int m)
{
    visited[s]=true;
    sp_table[s][0]=par;
    for(int i=1;i<m;i++)
    {
        sp_table[s][i]=sp_table[sp_table[s][i-1]][i-1];
    }
    for(auto u: adj[s])
    {
        if(visited[u]==false)
        {
            sparse_table(adj,visited,u,s,sp_table,n,m);
        }
    }
}

int lca_binary_lift(int u,int v,int depth[],vector<vector<int>> & sp_table,int m )
{
    if(u==v)
    return u;
    if(depth[u]<depth[v]) swap(u,v);
    int diff=depth[u]-depth[v];

    for(int i=m-1;i>=0;i--)
    {
        if((diff&(1<<(i)))!=0)

        {
            u=sp_table[u][i];
        }
    }
    
    
    
        //now the depth are same.
        if(u==v) return u;
          for(int i=m-1;i>=0;i--)
        {
            if(sp_table[u][i]!=sp_table[v][i])
            {
                u=sp_table[u][i];
                v=sp_table[v][i];
            }
        }

    // i am at last diff node;
    return sp_table[u][0];
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
    

    int x,y;
    cin>>x>>y;
    int m = log2(n-1)+2;

    vector<vector<int>> mat(n,vector<int>(m,0));


    int depth[n];
    depth[0]=0;


    bool visited[n];
    fill(visited,visited+n,false);
    dfs(adj,visited,0,depth);
    for(auto x: depth)
    cout<<x<<" ";
    cout<<endl;
    fill(visited,visited+n,false);
 
    
 
 
    sparse_table(adj,visited,0,0,mat,n,m);
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"-->";
        for(int j=0;j<m;j++)
        cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<lca_binary_lift(x-1,y-1,depth,mat,m)+1<<endl;

return 0;
}