#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Disjoint Set Union structure to manage connected components
struct DSU {
    vector<int> parent;
    vector<int> sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    // Find with path compression
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    
    // Union by size
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
        }
    }
    
    int get_size(int i) {
        return sz[find(i)];
    }
};

struct Edge {
    int u, v, w;
};

struct Query {
    int jump, id;
};

vector<int> solve(int n, vector<vector<int>> H, int Q, vector<int> Jump) {
    int total_cells = n * n;
    vector<Edge> edges;
    
    // 1. Generate all horizontal and vertical edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int u = i * n + j;
            if (j + 1 < n) { // Right neighbor
                edges.push_back({u, i * n + (j + 1), abs(H[i][j] - H[i][j + 1])});
            }
            if (i + 1 < n) { // Bottom neighbor
                edges.push_back({u, (i + 1) * n + j, abs(H[i][j] - H[i + 1][j])});
            }
        }
    }
    
    // 2. Sort edges by height difference
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });
    
    // 3. Prepare queries with original indices
    vector<Query> sorted_queries(Q);
    for (int i = 0; i < Q; i++) {
        sorted_queries[i] = {Jump[i], i};
    }
    sort(sorted_queries.begin(), sorted_queries.end(), [](const Query& a, const Query& b) {
        return a.jump < b.jump;
    });
    
    // 4. Process queries using DSU
    DSU dsu(total_cells);
    vector<int> results(Q);
    int edge_ptr = 0;
    
    for (int i = 0; i < Q; i++) {
        while (edge_ptr < (int)edges.size() && edges[edge_ptr].w <= sorted_queries[i].jump) {
            dsu.unite(edges[edge_ptr].u, edges[edge_ptr].v);
            edge_ptr++;
        }
        // Result for cell (1, 1), which is index 0
        results[sorted_queries[i].id] = dsu.get_size(0);
    }
    
    return results;
}
// ... (Keep the DSU struct and solve function from the previous response here) ...

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0; 

    while (T--) {
        int n;
        if (!(cin >> n)) break;

        vector<vector<int>> H(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> H[i][j];
            }
        }

        int Q;
        cin >> Q;
        vector<int> Jump(Q);
        for (int i = 0; i < Q; i++) {
            cin >> Jump[i];
        }

        // Calling the logic function
        vector<int> result = solve(n, H, Q, Jump);

        // Printing results for the current test case
        for (int i = 0; i < Q; i++) {
            cout << result[i] << (i == Q - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}