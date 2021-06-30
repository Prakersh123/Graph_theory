#include<bits/stdc++.h>
using namespace std;


bool cycle_detect(vector<int> adj[],bool visited[],bool recst[],int s)
{
    visited[s]=recst[s]=true;

    for(auto u: adj[s])
    {
        if(visited[u]==false)
        {
            if(cycle_detect(adj,visited,recst,u))
            return true;
        }
        else if(recst[u]==true)
        return true;
    }
    recst[s]=false;
    return false;
}

int main()
{
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
    bool print=false;
    bool visited[n]={false};
    bool recst[n]={false};
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            if(cycle_detect(adj,visited,recst,i))
            {
                cout<<"cycle"<<" ";
                print=true;
                break;
            }

        }
    }
    if(print==false)
    cout<<"No cycle"<<endl;


    return 0;
}