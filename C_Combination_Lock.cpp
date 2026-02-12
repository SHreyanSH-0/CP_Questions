#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> v;
        if(n%2==0){
            cout<<"-1\n";
        }
        else{
            for (int j = 1; j <= n; j += 2)
            {
                v.push_back(j);
            }
            for (int j = 2; j <= n; j += 2)
            {
                v.push_back(j);
            }
            
            for (int j = 0; j < n; j++)
            {
                cout << v[j] << " ";
            }
            cout << endl;
        }
    }
}