#include<bits/stdc++.h>
using namespace std;


int main()
{
    int no_of_transaction;
    cin>>no_of_transaction;
    int friends;
    cin>>friends;
    int x,y,amount;
    int net[100000]={0};
    //make a one d array to store the net ammount that each person will have to take at the end
    while(no_of_transaction--)
    {
        cin>>x>>y>>amount;
        net[x]-=amount;
        net[y]+=amount;
    }

    multiset<int> m;
    for(int i=0;i<friends;i++)
    {
        if(net[i])
        m.insert(net[i]);
    }
    //pop out two person from extreme left and right and make transaction between them
    int count=0;

    while(m.empty()==false)
    {
        count++;
        auto low =m.begin();
        auto right= prev(m.end());
        int debit = *low;
        int credit =*right;
        m.erase(low);
        m.erase(right);

        //settlement
        int amnt= min(-debit,credit);
        
        debit+=amnt;
        credit-=amnt;
        if(debit!=0)
        {
            m.insert(debit);

        }
        if(credit!=0)
        m.insert(credit);


    }
    cout<<count<<endl;
return 0;
}