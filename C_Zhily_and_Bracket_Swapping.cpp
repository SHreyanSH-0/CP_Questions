#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += (a[i] == '(');
        total += (b[i] == '(');
    }

    if (total != n) {
        cout << "NO\n";
        return;
    }

    int pref = 0;
    for (int i = 0; i < n; i++) {
        pref += (a[i] == '(');
        pref += (b[i] == '(');

        int k = i + 1;
        if (pref < k + (k & 1)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;
    while (test--) solve();
    return 0;
}