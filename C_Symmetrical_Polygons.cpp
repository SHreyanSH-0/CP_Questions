#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (n == 3)
    {
        if (!((v[0] + v[1] > v[2]) && (v[0] + v[2] > v[1]) && (v[2] + v[1] > v[0])))
        {
            cout << 0 << endl;
            return;
        }
    }

    int up = 0, down = 0, right = 0, left = 0;
    int tril,trir;

    sort(v.begin(), v.end());

    long long ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] == v[i + 1])
        {
            left++;
            right++;
            ans += v[i] + v[i + 1];
            tril = v[i];
            trir = v[i+1];
            v[i] = -1;
            v[i + 1] = -1;
            i++;
        }
    }

    sort(v.begin(), v.end());

    int r = n - 1;
    vector<int> a;
    int hold = ans;

    while (r >= 0 && v[r] != -1)
    {
        a.push_back(v[r]);
        r--;
    }

    if (a.size() == 0 && left+right > 3)
    {
        cout << ans << endl;
        return;
    }
    else{
        int one = -1;
        int two = -1;

        for (int i = 0; i < a.size(); i++)
        {
            if(a[i]<ans){
                one = a[i];
                break;
            }
        }

        for (int i = 0; i < a.size()-1; i++)
        {
            if(a[i]-a[i+1]<ans){
                two = a[i]+ a[i+1];
                up+=2;
                break;
            }
        }

        if(two!=-1) {
            ans+=two; 
            up+=2;
        }
        else if(one!=-1){
            ans+=one;
            up++;
        }
        else if(left + right == 2) {
            cout<<0<<endl;
            return;
        }
    }

    if(left==0){
        cout << 0 << endl;
        return;
    }

    cout << ans << endl;
    return;
}

signed main()
{

    ll test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
