#include<bits/stdc++.h>
using namespace std;
#define int long long 
// sparsetable[n][log2(n)+1];
//sparsetable[i][j]----> this keeps the ans of range starting from ith index. And the length of this range is always 2^j
//i.e    [i, i+2^j-1]   
// we can get the answer in two parts   mat[i][j-1] --> [i,i+2^(j-1)-1]  , mat[i+2^(j-1)][j-1]; 




int32_t main()
{

    int n;
    cin>>n;   //also no of rows in sparse table.

    int arr[n];
int log[n+1];
log[1] = 0;
for (int i = 2; i <=n; i++)
       log[i] = log[i/2] + 1;
    for(int i=0;i<n;i++)
    cin>>arr[i];

    int m = log[n]+1;   //Enough No of coloumns for sparse table. 


    m++;
    int mat[n][m];

    for(int i=0;i<n;i++)
    {
        mat[i][0]=arr[i];
    }
    for(int j=1;j<m;j++)
    {
        for(int i=0;(i+(1<<(j-1)))<n;i++)
        {
            mat[i][j]=min(mat[i][j-1],mat[i+(1<<(j-1))][j-1]);
        }
    }

    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int diff= r-l+1;

        int val= log[diff]  ;
        cout<<min(mat[l][val],mat[r-(1<<(val))+1][val])<<endl;

    }
    return 0;
}

