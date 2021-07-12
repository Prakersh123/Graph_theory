#include<bits/stdc++.h>
using namespace std;

void euler(vector<int> adj[],bool visited[],int s,int time_in[],int time_out[],int &timer)
{


    visited[s]=true;
for(auto u: adj[s])
        if(visited[u]==false)
        {
            time_in[u]=++timer;
            euler(adj,visited,u,time_in,time_out,timer);
        }

      time_out[s]=timer;  
}
void sparse_table(vector<int> adj[],bool visited[],int s,int par,vector<vector<int>> & sp_table,int m)
{
    visited[s]=true;
    sp_table[s][0]=par;
    for(int i=1;i<m;i++)
    sp_table[s][i]=sp_table[sp_table[s][i-1]][i-1];


    for(auto u: adj[s])
    {
        if(!visited[u])
        {
            sparse_table(adj,visited,u,s,sp_table,m);
        }
    }


}


int lca_binary_lift(int u ,int v ,int time_in[],int time_out[],vector<vector<int> > sp_table,int m )
{
    if(u==v) return u;
    
    for(int i= m-1;i>=0;i--)
    {
        if(time_in[sp_table[u][i]]<=time_in[v] and time_out[sp_table[u][i]]>=time_out[v]);
        else 
        {
            u=sp_table[u][i];
        }
    }
    return sp_table[u][0];
}

int main()
{
    int n;
    cin>>n; 
    int m = log2(n-1)+2;
    // int sp_table[n][m];
    vector<vector<int> > sp_table(n,vector<int>(m,0));
    int e;
    cin>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    bool visited[n];
    fill(visited,visited+n,false);
    int time_in[n]={0};
    int time_out[n]={0};
    int timer=1;
    time_in[0]=timer;
    euler(adj,visited,0,time_in,time_out,timer);

    fill(visited,visited+n,false);
    sparse_table(adj,visited,0,0,sp_table,m);

    int x,y;
    cin>>x>>y;
    cout<<lca_binary_lift(x-1,y-1,time_in,time_out,sp_table,m)+1<<endl;
return 0;
}