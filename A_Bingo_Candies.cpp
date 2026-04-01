#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;

struct Line {
    long long m, b;
    long long eval(long long x) { return m * x + b; }
};

bool is_bad(const Line& l1, const Line& l2, const Line& l3) {
    return (long double)(l2.b - l1.b) * (l2.m - l3.m) >= (long double)(l3.b - l2.b) * (l1.m - l2.m);
}

long long solve_value(const vector<int>& p, int K) {
    int m = p.size();
    if (m < 2) return 0;

    vector<long long> s(m + 1, 0);
    for (int i = 0; i < m; ++i) s[i + 1] = s[i] + p[i];

    vector<long long> dp(m, -2e18);
    dp[0] = 0;

    deque<Line> dq;
    int ptr = 0;
    long long best = 0;

    for (int j = 1; j < m; ++j) {
        while (ptr < j && p[j] - p[ptr] >= K) {
            if (dp[ptr] > -1e18) {
                Line cur = {(long long)-ptr, dp[ptr] + s[ptr]};
                while (dq.size() >= 2 && is_bad(dq[dq.size() - 2], dq.back(), cur)) {
                    dq.pop_back();
                }
                dq.push_back(cur);
            }
            ptr++;
        }

        if (!dq.empty()) {
            while (dq.size() >= 2 && dq[0].eval(p[j]) <= dq[1].eval(p[j])) {
                dq.pop_front();
            }
            dp[j] = (long long)j * (long long)p[j] - s[j] + dq[0].eval(p[j]);
            best = max(best, dp[j]);
        }
    }
    return best;
}

long long solve(int N, int K, long long* A) {
    map<long long, vector<int>> groups;
    for (int i = 0; i < N; ++i) {
        groups[A[i]].push_back(i);
    }

    long long res = 0;
    for (auto const& [val, pos] : groups) {
        res = max(res, solve_value(pos, K));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // if (!(cin >> T)) return 0;
    while (T--) {
        int N, K;
        if (!(cin >> N >> K)) break;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        cout << solve(N, K, A.data()) << "\n";
    }

    return 0;
}