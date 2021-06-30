#include<bits/stdc++.h>
using namespace std;

          //top right bottom left i.e clockwise  
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};

void flood_fill(int mat[][30],int i ,int j ,int ch,int color)
{
    //matrix bound
    if(i<=0 || j<=0 || i>=15 || j>=30)
    return ;

    //region bound
    if(mat[i][j]!=ch)
    return ;
    for(int k=0;k<4;k++)
    flood_fill(mat,i+di[k],j+dj[k],ch,color);


}




int main()
{
    int mat[15][30];
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<30;++j)
        {
            cin>>mat[i][j];
        }
    }

    for(int i=0;i<15;i++)
    {
        cout<<endl;
        for(int j=0;j<30;++j)
        {
            cout<<mat[i][j]<<" ";
        }
    }

    flood_fill(mat,8,13,'.','R');

for(int i=0;i<15;i++)
    {
        cout<<endl;
        for(int j=0;j<30;++j)
        {
            cout<<mat[i][j]<<" ";
        }
    }

}