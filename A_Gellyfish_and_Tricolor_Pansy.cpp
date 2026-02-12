#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
class p{
    public:
        static void print(vector<int> v){
            int n= v.size();
            for (int i = 0; i < n; i++)
            {
                cout<<v[i]<<" ";
            }cout<<endl;
            
        }
        static void print(unordered_map<int,int> map){
            for(auto i : map)
            {
                cout<<i.first<<" "<<i.second<<" ";
            }cout<<endl;
            
        }
};

void solve()
{
    int a,b,c,d;
    
    cin>>a>>b>>c>>d;

    a = min(a,c);
    b = min(b,d);
    if(a==b){
        cout<<"Gellyfish\n";
    }
    else if(a<b){
        cout<<"Flower\n";
        
    }
    else{
        cout<<"Gellyfish\n";

    }

    vector<int> v = {1,2,4,5,1,151,1};
    unordered_map<int ,int> map = {
        {1,1},{2,2},{100,111111}
    };

    p::print(v);
    p::print(map);
    
}

int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
