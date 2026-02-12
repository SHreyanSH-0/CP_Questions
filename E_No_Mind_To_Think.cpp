#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        vector<ll> pre(n);
        pre[0] = a[0];
        for (int i = 1; i < n; ++i) pre[i] = pre[i-1] + a[i];
        auto range_sum = [&](int L, int R)->ll {
            if (L > R) return 0;
            ll res = pre[R];
            if (L) res -= pre[L-1];
            return res;
        };
        ll base = pre[n-1];
        ll ans = base;

        // iterate median index i
        for (int i = 0; i < n; ++i) {
            // y can be from 0 up to min(i, n-i-1). We'll binary-search on m = number of "groups"
            // following editorial: search over number of groups mid in [1..min(i,n-i-1)+1), then adjust.
            int L = 1;
            int R = min(i, n - i - 1) + 1;
            while (L < R) {
                int mid = (L + R) / 2;
                // left range indices that would be increased in this "mid" step:
                // left = min((mid-1)*k, i)
                // right = min(mid*k - 1, i)
                ll left = min(1LL*(mid - 1) * k, 1LL * i);
                ll right = min(1LL*mid * k - 1, 1LL * i);
                if (left > right) {
                    // nothing to compare; move
                    L = mid + 1;
                    continue;
                }
                // cost check: see if raising these elements up to a[i] is still worthwhile
                // We compare sum of elements in [left..right] plus a[i+mid] with a[i] * (count + 1)
                // (this check mirrors editorial's monotonic predicate)
                ll cnt = (right - left + 1) + 1; // +1 for the a[i+mid] element considered on right side
                // query sum of a[left..right]  (these are from smallest side)
                ll sLR = range_sum((int)left, (int)right);
                // a[i+mid] exists because mid <= n-i-1 + 1, bounds ensured by R init
                ll ai_mid = (i + mid < n ? a[i + mid] : 0);
                ll cost = sLR + ai_mid;
                if (cost <= a[i] * cnt) L = mid + 1;
                else R = mid;
            }
            int m = L - 1; // number of groups we can take positively
            if (m == 0) continue;
            // compute final contribution when using m groups:
            int right = (int)min(1LL * m * k - 1, 1LL * i);
            ll len = right + 1 + m; // how many positions become a[i] (right side part + median positions counted)
            // total gain = len*a[i] - (sum of those elements before changed + sum of those right elements we decreased)
            ll sum_left_part = range_sum(0, right);
            ll sum_right_part = range_sum(i + 1, i + m);
            ll gain = len * a[i] - (sum_left_part + sum_right_part);
            ans = max(ans, base + gain);
        }

        cout << ans << '\n';
    }
    return 0;
}
