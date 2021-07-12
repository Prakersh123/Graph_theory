#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[],bool visited[],int s,int x,stack<int> &st)
{
    if(s==x)
    {
        st.push(s);
        return true;
    }
    visited[s]=true;
    st.push(s);
    for(auto u: adj[s])
    {
        if(visited[u]==false)
        {
            if(dfs(adj,visited,u,x,st))
            return true;
        }
    }
    st.pop();
    return false;
}



int main()
{
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<int> adj[n];

    for(int i =0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool visited[n];
    fill(visited,visited+n,false);
    int x,y;
    cout<<"enter x y";
    cin>>x>>y;
    x--;
    y--;
    stack<int> st_x,st_y;
    dfs(adj,visited,0,x,st_x);
    fill(visited,visited+n,false);
    dfs(adj,visited,0,y,st_y);


    // while(st_x.empty()==false)
    // {
    //     cout<<st_x.top()<<" ";
    //     st_x.pop();
    // }
    // cout<<endl;
    // while(st_y.empty()==false)
    // {
    //     cout<<st_y.top()<<" ";
    //     st_y.pop();
    // }
    if(st_x.size()==st_y.size())
    {
        while(st_x.top()!=st_y.top())
        {
            st_x.pop();
            st_y.pop();
        }
        cout<<endl<<st_x.top()+1;
    }
    else if(st_x.size()>=st_y.size())
    {
        while(st_x.size()!=st_y.size())
        {
            st_x.pop();
        }
         while(st_x.top()!=st_y.top())
        {
            st_x.pop();
            st_y.pop();
        }
        cout<<endl<<st_x.top()+1;
    }
    else 
    {
        /* code */
         while(st_x.size()!=st_y.size())
        {
            st_y.pop();
        }
         while(st_x.top()!=st_y.top())
        {
            st_x.pop();
            st_y.pop();
        }
        cout<<endl<<st_x.top()+1;
    }




}