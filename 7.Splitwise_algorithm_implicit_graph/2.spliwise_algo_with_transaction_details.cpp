#include<bits/stdc++.h>
using namespace std;

class person_comp{
    public:
    bool operator()(pair<string,int> p1,pair<string,int> p2){
        return p1.second<p2.second;
    }
};

int main()
{
    int no_of_transaction;
    cin>>no_of_transaction;
    int friends;
    cin>>friends;
        string x,y;
        int amount;
        map<string,int> net;
        while(no_of_transaction--)
        {
            cin>>x>>y>>amount;
            if(net.count(x)==0)
            {
                net[x]=0;
            }
            if(net.count(y)==0)
            {
                net[y]=0;
            }
            net[x]-=amount;
            net[y]+=amount;
        }


        //iterate over the persons, add those person in the multiset who have non zero transaction

    multiset<pair<string,int>,person_comp>m;
        for(auto p:net)
        {
            string person = p.first;
            int amount =p.second;
            if(net[person])
            {
                m.insert(make_pair(person,amount));
            }
        }

        //making sattlements;
        int cnt=0;
        while(!m.empty())
        {
            auto low= m.begin();
            auto high = prev(m.end());
            int debit = low->second;
            string debit_name =low->first;
            int credit = high->second;
            string credit_name =high->first;
            
            m.erase(low);
            m.erase(high);

            int settled_amount  = min(-debit,credit);

            debit+= settled_amount;
            credit-= settled_amount;

            cout<<debit_name<<"will par"<<settled_amount<<"to "<<credit_name<<endl;

            if(debit!=0)
            {
                m.insert(make_pair(debit_name,debit));
            }
            if(credit!=0)
            {
                m.insert(make_pair(credit_name,credit));
            }
        }
        



    

    
    // cout<<count<<endl;
return 0;
}