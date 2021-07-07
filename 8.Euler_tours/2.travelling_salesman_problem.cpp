#include<bits/stdc++.h>
using namespace std;

int n=4;



int dist[10][10]={
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};

int VISITED_ALL= (1<<n)-1;


    int tsp(int mask,int pos)
    {
        if(mask==VISITED_ALL)
        {
            return dist[pos][0];
        }
        int ans= INT_MAX;
        for(int i=0;i<n;i++)
        {
            if((mask&(1<<i))==0)
            {
                int newAns = dist[pos][i]+tsp((mask|(1<<i)),i);
                ans = min(ans,newAns);
            }
        }

        return ans;
    }


int main()
{


    cout<<tsp(1,0)<<endl;
    return 0;

}