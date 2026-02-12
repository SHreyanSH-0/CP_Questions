#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int m=0;m<t;m++){
        string s;
        cin>>s;
        string ans;
        int a = 9;
        for (int i = 0; i < 10; i++)
        {
            int m = 10;
            int index = -1;
            for(int j = 0;j<10;j++){
                if(s[j]-48>=a&&s[j]!='a'){
                    if(m>s[j]-48){
                        m = s[j]-48;
                        index = j;
                    }
                }
            }
            if(index!=-1){
                s[index] = 'a';
            }
            if(m!=10){
                ans.push_back(m+48);
            }
            a--;
        }
        
        cout<< ans<<endl;
        
    }
}