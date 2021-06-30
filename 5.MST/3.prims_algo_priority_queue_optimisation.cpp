#include<bits/stdc++.h>
using namespace std;


// T.C   O(V+E) + O(V^2) = O(V2)

// int prim_mst(vector<pair<int,int>> adj[],int n)
// {
//     int res=0;
//     int key[n];
//     fill(key,key+n,INT_MAX);
//     key[0]=0;
//     bool mst[n];
//     fill(mst,mst+n,false);
//     for(int count =0;count<n;count++)
//     {
//         int u =-1;
//         for(int i=0;i<n;i++)
//       {  if(!mst[i] and (u==-1 or key[i]<key[u]))
//         u=i;
//       }
//         mst[u]=true;
//     res+=key[u];

//     for(auto x: adj[u])
//     {
//         if(!mst[x.first])
//         {
//             key[x.first] = min(key[x.first],x.second);
//         }
//     }
//     }
    

// return res;

// }


// T.C O(ElogV)
int prim_mst(vector<pair<int,int>> adj[],int n)
{
    int ans =0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    bool mst[n]={false};
    for(int count=0;count<n;count++)
    {
        while(pq.empty()==false and mst[pq.top().second]==true)
        {
            pq.pop();
        }
        auto x = pq.top();
        pq.pop();
        ans+=x.first;
        mst[x.second]=true;
        for(auto u : adj[x.second])
        {
            if(!mst[u.first])
            {
                pq.push({u.second,u.first});
            }
        }
    }
    return ans;

}



int main()
{

        //vertex
        int n;
        cin>>n;
        //edges
        int e;
        cin>>e;
        //adj. list
        vector<pair<int,int>> adj[n];
        for(int i=0;i<e;i++)
        {   
            int u ,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

        }

        cout<<prim_mst(adj,n)<<endl;


}