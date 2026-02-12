#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m; // forest size

    int k;
    cin >> k; // number of trees initially burning

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

    // Read all starting fire coordinates
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        q.push({{x, y}, 0});
        vis[x][y] = 1;
    }

    // directions: up, right, down, left
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int lastX = -1, lastY = -1, time = 0;

    // Multi-source BFS
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        q.pop();

        // track last burned position
        lastX = x;
        lastY = y;
        time = t;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({{nx, ny}, t + 1});
            }
        }
    }

    cout << lastX << " " << lastY << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // redirect I/O to files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
    return 0;
}
