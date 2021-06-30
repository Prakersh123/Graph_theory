//Graph: It's a collection of vertex and edges;
//Two types of graph: (1) Directed graph            (2) Undirected graph
                   // (a) Weighted graph   (b) Unweighted graph
//Representaion of Graph : (a) Adjecency list   (b)Adjecency Matrix 

//Traversal :   (a) Breadth first traversal (Iterative)
//              (b) Depth first search(Recursive)


#include <bits/stdc++.h>
using namespace std;

//time complexity O(N);


void depth_first_search(vector<int> adj[],bool visited[],int s)
{
    visited[s]=true;
    // cout<<s<<" ";
    for(auto u: adj[s])
    {
        if(visited[u]==false)
        depth_first_search(adj,visited,u);
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
    int connected=0;
    bool visited[n]={false};
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false){
            connected++;
        depth_first_search(adj,visited,i);
    }
    }

        cout<<connected<<endl;
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


