#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        vector<pair<int,int>> ans;
        set<int> one,two,zero;
        int j = 0;
        int k = n-1;
        for(int i=0;i<n;i++) {
            if(v[i]==0) zero.insert(i); 
            if(v[i]==1) one.insert(i); 
            if(v[i]==2) two.insert(i); 
        }
        int ct= zero.size(), ct2 = one.size();
        for (int i = 0; i < n; i++)
        {
            if(ct>0){
                if(v[i]==2){
                    int hold = *(one.rbegin());
                    swap(v[i],v[hold]);
                    ans.push_back({i+1,hold+1});
                    one.insert(i);
                    one.erase(hold);
                    two.insert(hold);
                    two.erase(i);
                }
                if(v[i]==1){
                    int hold = *(zero.rbegin());
                    swap(v[i],v[hold]);
                    ans.push_back({i+1,hold+1});
                    zero.insert(i);
                    zero.erase(hold);
                    one.insert(hold);
                    one.erase(i);
                }
                ct--;

            }
            else if(ct2>0){
                if(v[i]==2){
                    int hold = *(one.rbegin());
                    swap(v[i],v[hold]); 
                    ans.push_back({i+1,hold+1});
                    two.insert(hold);
                    two.erase(i);
                    one.insert(i);
                    one.erase(hold);
                }
                ct2--;
            }
        }
        
        
        
        
        cout<<ans.size()<<endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        
        
    }
}