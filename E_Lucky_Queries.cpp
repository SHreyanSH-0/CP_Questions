#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void build(int i,int l,int r, vector<pair<int,pair<int,int>>>&seg,string&s){
    if(l==r){
        if(s[l]=='4') {
            seg[i].first = 1;
            seg[i].second.first = 0;
            seg[i].second.second = 0;
        }
        else{
            seg[i].first = 0;//444444
            seg[i].second.first = 1;//77777777
            seg[i].second.second = 0;//44444777777
        }
    }
    else{
        int mid = (l+r)/2;
        build(2*i+1,l,mid,seg,s);
        build(2*i+2,mid+1,r,seg,s);

        //444444
        seg[i].first = seg[2*i+1].first + seg[2*i+2].first;

        //777777
        seg[i].second.first = seg[2*i+1].second.first + seg[2*i+2].second.first;
        
        //4444444777777777

        //44444 + 7777777
        if(seg[2*i+1].first>0&&seg[2*i+2].second.first>0)
        seg[i].second.second = max(seg[i].second.second,seg[2*i+1].first+seg[2*i+2].second.first);
        //44444777777 + 7777777
        if(seg[2*i+1].second.second > 0)
        seg[i].second.second = max(seg[i].second.second,seg[2*i+1].second.second + seg[2*i+2].second.first);
        //44444 + 4444447777777
        if(seg[2*i+1].second.second > 0)
        seg[i].second.second = max(seg[i].second.second,seg[2*i+1].second.first + seg[2*i+2].second.second);
    }
}   


void update(int start, int end, int i,int l,int r,vector<pair<int,pair<int,int>>>&seg, vector<int>&lazy){
    if(lazy[i]!=0){
        if(lazy[i]%2==1){
            
            int a4 = seg[i].first;
            int a7 = seg[i].second.first;
            int a47 = seg[i].second.second;

            


        }
        if(l!=r){
            lazy[2*i+1] ++;
            lazy[2*i+2] ++;
        }
        lazy[i] = 0;
        return;
    }

    if(r<start||l>end) return;
    if(l>=start&&r<=end){
        
        if(l!=r){
            lazy[2*i+1] ++;
            lazy[2*i+2] ++;
        }
        return;
    }

    int mid = (l+r)/2;

    update(start,end,2*i+1,l,mid,seg,lazy);
    update(start,end,2*i+2,mid+1,r,seg,lazy);

    //444444
    seg[i].first = seg[2*i+1].first + seg[2*i+2].first;

    //777777
    seg[i].second.first = seg[2*i+1].second.first + seg[2*i+2].second.first;
    
    //4444444777777777

    //44444 + 7777777
    if(seg[2*i+1].first>0&&seg[2*i+2].second.first>0)
    seg[i].second.second = max(seg[i].second.second,seg[2*i+1].first+seg[2*i+2].second.first);
    //44444777777 + 7777777
    if(seg[2*i+1].second.second > 0)
    seg[i].second.second = max(seg[i].second.second,seg[2*i+1].second.second + seg[2*i+2].second.first);
    //44444 + 4444447777777
    if(seg[2*i+1].second.second > 0)
    seg[i].second.second = max(seg[i].second.second,seg[2*i+1].second.first + seg[2*i+2].second.second);


}

void solve()
{
    int n,q;
    cin>>n>>q;

    string s;
    cin>>s;
    vector<pair<int,pair<int,int>>> seg(4*n,{0,{0,0}});
    vector<int> lazy(4*n,0);
    build(0,0,n-1,seg,s);
    for (int i = 0; i < q; i++)
    {
        string hold;
        cin>>hold;
        if(hold=="count"){

        }
        else{
            int l,r;
            cin>>l>>r;
            l--;r--;
            update(l,r,0,0,n-1,seg,lazy);
        }
    }
    
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
