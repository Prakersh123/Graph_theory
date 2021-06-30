#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],bool visited[],int distance[],int s)
{
        visited[s]=true;
        queue<int> q;
        q.push(s);
        while(q.empty()==false)
        {
            int v = q.front();
            q.pop();
            for(auto u: adj[v])
            {
                if(visited[u]==false)
                {
                    visited[u]=true;
                    distance[u]=distance[v]+1;
                    q.push(u);
                }
            }
        }


}

int main()
{
    int jump[37]={0};
    jump[2]=13;
    jump[5]=2;
    jump[9]=18;
    jump[18]=11;
    jump[17]=-13;
    jump[20]=-14;
    jump[24]=-8;
    jump[25]=10;
    jump[34]=-22;
    jump[32]=-2;
    vector<int> adj[37];
    for(int i=1;i<=36;i++)
    {
        if(jump[i]!=0)
        continue;
        for(int j=1;j<=6;j++)
        {
            int u=i+j+jump[i+j];
            if(u<=36 && u>=1)
            adj[i].push_back(u);
        }    
    }

    int distance[37]={0};
    bool visited[37]={false};
    for(int i=1;i<=36;i++)
    {
        if(visited[i]==false)
        bfs(adj,visited,distance,i);
    }
    cout<<distance[36]<<endl;
}