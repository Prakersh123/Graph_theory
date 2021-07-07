#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int> > >m;

    public:
    void addEdge(T u, T v,int dist,bool bidir=true)
    {
        m[u].push_back({v,dist});
        if(bidir)
        m[v].push_back({u,dist});
    }
    void printAdj()
    {
        for(auto j:m)
        {
        cout<<j.first<<"->";

            for(auto x: j.second)
            {
                cout<<"("<<x.first<<","<<x.second<<")"<<" ";
            }
            cout<<endl;
        }
    }
    void dijkstra_sssp( T src)
    {
        unordered_map<T,int> dist;
        //set all distance to infinite

        for(auto j: m)
        {
            dist[j.first]=INT_MAX;
        }

        //make a set to find out node with the minimum distance
        set<pair<int,T>> s;
        dist[src]=0;
        s.insert(make_pair(0,src));
        while(s.empty()==false)
        {
            //pick the pair with minimum distance
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            

            //iterate over the adjacents of this node
            for(auto child: m[node])
            {
                if(nodeDist+child.second < dist[child.first])
                {
                    auto f = s.find(make_pair(dist[child.first],child.first));
                    if(f!=s.end())
                    {
                        s.erase(f);

                    }
                    dist[child.first] = nodeDist+child.second; 
                    s.insert(make_pair(dist[child.first],child.second));
                }
            }

        }

        for(auto x: dist)
        {
            cout<<x.first<<"-->"<<x.second<<endl;
        }
    }


};

int main()
{
    Graph<string> india;
    india.addEdge("amritsar","Delhi",1);
    india.addEdge("amritsar","jaipur",4);
    india.addEdge("jaipur","Delhi",2);
    india.addEdge("jaipur","mumbai",8);
    india.addEdge("bhopal","agra",2);
    india.addEdge("mumbai","bhopal",3);
    india.addEdge("agra","Delhi",1);
    // india.printAdj();
    india.dijkstra_sssp("amritsar");

    

}




