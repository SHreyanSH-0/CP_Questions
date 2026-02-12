#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    int x = 0, y = 0;
    set<pair<int,int>> set;
    set.insert({0,0});
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='L'){
            x--;
            vector<pair<int,int>> v = {{x-1, y}, {x,y+1},{x,y-1}};
            for (int j = 0; j < 3; j++)
            {
                if(set.find(v[j])!=set.end()){
                    cout<<"BUG"<<endl;
                    return;
                }
            }
            
        } 
        else if(s[i]=='R') {
            x++;
            vector<pair<int,int>> v = {{x+1, y}, {x,y+1},{x,y-1}};
            for (int j = 0; j < 3; j++)
            {
                if(set.find(v[j])!=set.end()){
                    cout<<"BUG"<<endl;
                    return;
                }
            }
        }
        else if(s[i]=='U'){
            y++;
            vector<pair<int,int>> v = {{x, y+1}, {x+1,y},{x-1,y}};
            for (int j = 0; j < 3; j++)
            {
                if(set.find(v[j])!=set.end()){
                    cout<<"BUG"<<endl;
                    return;
                }
            }
        } 
        else{
            y--;
            vector<pair<int,int>> v = {{x, y-1}, {x+1,y},{x-1,y}};
            for (int j = 0; j < 3; j++)
            {
                if(set.find(v[j])!=set.end()){
                    cout<<"BUG"<<endl;
                    return;
                }
            }

        } 
        if(set.find({x,y})!=set.end()){
            cout<<"BUG"<<endl;
            return;
        }
        else set.insert({x,y});
    }
    
    cout<<"OK"<<endl;    
}
signed main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
