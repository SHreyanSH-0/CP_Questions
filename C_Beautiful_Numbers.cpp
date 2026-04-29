#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;

struct DSU {
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }
};


long long getMaxRemovedChannelCost(int org_nodes, vector<int> org_from, vector<int> org_to, vector<int> org_weight) {
    ll ans = 0;

    vector<vector<ll>> edges;
    for (int i = 0; i < org_from.size(); i++)
    {
        edges.push_back({org_weight[i],org_from[i], org_to[i]});
    }
    dsu d(org_nodes);
    sort(edges.begin(),edges.end());
    int idx = edges.size();
    for (int i = 0; i < edges.size(); i++)
    {
        if(edges[i][0]<=0){
            d.unite(edges[i][1],edges[i][2]);
        }
        else{
            idx = i;
            break;
        }
    }

    for (int i = idx; i < edges.size(); i++)
    {
        int para = d.find(edges[i][1]);
        int par2 = d.find(edges[i][2]);

        if(para==parb) ans += edges[i][0];
        else {
            d.unite(edges[i][1],edges[i][2]);
        }
    }

    return ans;
}