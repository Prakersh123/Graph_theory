#include<bits/stdc++.h>
using namespace std;

void euler_tour_1(vector<int> adj[],bool visited[],int s)
{
    visited[s]=true;
    // time_in[s]=count;
    cout<<s<<" ";
    for(auto u: adj[s])
    {
        if(visited[u]==false)
        {
            euler_tour_1(adj,visited,u);
            cout<<s<<" ";
        }
    }
}

//remover cout of this function if you do not want to print euler path.
void euler_tour_2(vector<int> adj[],bool visited[],int s,int time_in[],int time_out[],int &timer)

{
    visited[s]=true;
    cout<<s<<" ";
    time_in[s]=timer;

    for(auto u: adj[s])
    {
        if(visited[u]==false)
        {
            timer++;

            euler_tour_2(adj,visited,u,time_in,time_out,timer);

        }
    }
    time_out[s]=++timer;

        cout<<s<<" ";
}

//remove cout if euler path not needed.
void euler_tour_3(vector<int> adj[],bool visited[],int s,int time_in[],int time_out[],int &timer)
{
    visited[s]=true;
    cout<<s<<" ";
   time_in[s]=timer;
    for(auto u: adj[s])
    {
        if(visited[u]==false)
        {
            timer++;
            euler_tour_3(adj,visited,u,time_in,time_out,timer);
        }
    }
    time_out[s]=timer;
        // cout<<s<<" ";
}


bool is_ancestor(int x,int y,int time_in[],int time_out[])
{
    if(time_in[x]<=time_in[y] and time_out[x]>=time_out[y])
    return true;
    return false;
}

int main()
{


    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<int> adj[n];
    bool visited[n];
    fill(visited,visited+n,false);
    int time_in[n];
    int time_out[n];
    int timer=1;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

        // euler_tour_1(adj,visited,0);
        // euler_tour_2(adj,visited,0,time_in,time_out,timer);
    //     euler_tour_3(adj,visited,0,time_in,time_out,timer);
    // cout<<endl;
    // cout<<is_ancestor(2,7,time_in,time_out);
    // cout<<is_ancestor(1,8,time_in,time_out);

    return 0;

}