#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        stack<char> s;
        string st;
        cin>>st;
        s.push(st[0]);
        string ans = "NO";
        int j;
        for (j = 1; j < st.size(); j++)
        {
            if(s.empty()){
                ans = "YES";
                break;
            }

            if(s.top()=='('&&st[j]==')'){
                s.pop();
            }
            else{
                s.push(st[j]);
            }

        }
        
        cout<<ans<<endl;
        
    }
}