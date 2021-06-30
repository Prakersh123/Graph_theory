//Graph: It's a collection of vertex and edges;
//Two types of graph: (1) Directed graph            (2) Undirected graph
                   // (a) Weighted graph   (b) Unweighted graph
//Representaion of Graph : (a) Adjecency list   (b)Adjecency Matrix 

//Traversal :   (a) Breadth first traversal (Iterative)
//              (b) Depth first search(Recursive)


#include <bits/stdc++.h>
using namespace std;

//time complexity O(N);
void breadth_first_search(vector<int> adj[],int n,bool visited[],int source,int distance[])
{
    visited[source] =true;
    queue<int> q;
    q.push(source);

    while(q.empty()==false)
    {
       int u= q.front();
        q.pop();
        // cout<<u<<" ";
        for(auto v: adj[u])
        {
            if(visited[v]==false)
            {
                q.push(v);
                visited[v]=true;
                distance[v]+=distance[u]+1;
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
    for(int i=0;i<e;++i)
    {   int u,v; 
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool visited[n]={false};
    int distance[n]={0};
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        breadth_first_search(adj,n,visited,i,distance);
    }

    for(auto x: distance)
    {
        cout<<x<<endl;
    }

    // //adjecency matrix;
    // // space complexity   O(n^2)
    // int adj[n][n]={0};
    // for(int i=0;i<e;++i)
    // {   int u,v; 
    //     cin>>u>>v;
    //     adj[u][v]=1;
    //     adj[v][u]=1;
    // }

    // //Hash map
    // unordered_map <int,list<int>> adj;
    // for(int i=0;i<e;++i)
    // {   int u,v; 
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //            adj[v].push_back(u);

    // }


//display graph
    // for(int i=0;i<n;i++)
    // {
    //     cout<<i;
    //     for(auto v: adj[i])
    //     cout<<"-->"<<v;
    //     cout<<endl;
    // }
    
    return 0;

}


