class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        // Attach smaller tree to larger tree
        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }

    int size_of(int a) {
        return size[find(a)];
    }

    void change(int a, int b){
        size[find(a)] = b;
    }
};


class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        DSU d(1e5+1);
        unordered_map<int,int> is;
        vector<int> vis(1e5+1, false);
        int ans = 0;
        for(int i=0;i<n;i++) is[nums[i]]++;

        for(int i=2;i<=1e5;i++){
            if(vis[i]) continue;
            for(int j=i;j<=1e5;j+=i){
                vis[j] = true;
                if(is[j] > 0){
                    d.unite(i,j);
                }
            }

            if(is[i]==0){
                d.change(i,d.size_of(i)-1);
            }

            ans = max(ans, d.size_of(i));


        }
        return ans;
    }
};