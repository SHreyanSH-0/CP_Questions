#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> v;
        int zero = 0, one , two, three , five;
        one = two = three = five = 0;
        int ans = 0;
        for(int j=0;j<n;j++){
            int hold;
            cin>>hold;
            if(hold==0)
                zero++;
            else if(hold==1)
                one++;
            else if(hold==2)
                two++;
            else if(hold==3)
                three++;
            else if(hold==5)
                five++;

            if(zero>=3 && two>=2 && three>=1 && one>=1 && five>=1 && ans==0)
                ans = j+1;
        }
        cout<<ans<<endl;

    }
}