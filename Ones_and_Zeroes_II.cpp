#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt1 = 0;
        for (char c : s) {
            if (c == '1') cnt1++;
        }
        int cnt0 = n - cnt1;

        int max_good;
        if (cnt1 >= cnt0) max_good = n;
        else max_good = 2*cnt1;

        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') pos.push_back(i);
        }

        long long swaps = 0;
        int idx = 0;
        int one = 0, zero = 0;
        for (int i = 0; i < n && idx < cnt1; i++) {
            if(s[i]=='1'){
                idx++;
                one++;
            }
            else{
                zero++;
                if(one<zero){
                    swaps += abs(pos[idx] - i);
                    one++;
                    zero--;
                    s[pos[idx]] = '0';
                    idx++;
                }
            }
        }
        cout << max_good << " " << swaps << "\n";
    }
}