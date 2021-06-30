#include<iostream>
#include<list>
using namespace std;


class Graph{
    int V;
    list<pair<int,int>> l;   //edge list representation.

    public:
        Graph(int V){
            this->V= V;
        }

        void addEdge(int u,int v){
            l.push_back(make_pair(u,v));
        }
    //Find function

    int findSet(int i,int parent[])
    {
        if(parent[i]==-1)return i;
        //this is normal case O(n)
        // return findSet(parent[i],parent);
        //this is path compression that is just store the result 

        return parent[i] = findSet(parent[i],parent);
    }

    bool union_set(int x,int y,int parent[],int rank[])
    {
        int s1= findSet(x,parent);
        int s2= findSet(y,parent);
        if(s1==s2) return false;
        if(rank[s1]<rank[s2])
        {
        parent[s1]=s2;
        rank[s2]+=rank[s1];
        }
        else 
        {
            parent[s2]=s1;
            rank[s1]+=s2;
        }        
        parent[s2]=s1;
        return true;
    }


    bool contains_cyle(){
        //we will use dsu logic for this.
        int* parent = new int[V];

        int* rank = new int[V];

        for(int i=0;i<V;i++)
        {parent[i]=-1;
            rank[i]=1;  //because each set has one element initially
        }
        for(auto edge: l)
        {
            int i =edge.first;
            int j = edge.second;
            if(union_set(i,j,parent,rank));
            else 
            {
                cout<<"Cycle is there";
                return true;
            }
        }
        delete [] parent;
        cout<<"No cylce";
        return false;


    }



};

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,6);
    g.addEdge(2,5);
    g.addEdge(5,6);


    



    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,0);
    cout<<g.contains_cyle()<<endl;



    return 0;
}

