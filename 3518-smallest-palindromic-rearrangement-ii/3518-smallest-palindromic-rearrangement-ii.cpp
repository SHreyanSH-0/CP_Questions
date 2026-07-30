class Solution {
public:

    long long mod = 1e9 + 7;
    vector<long long> fact,infact;
    long long power(long long a, long long b){
        long long ans = 1;
        
        while(b > 0){
            if(b%2==1) ans = (ans*a)%mod;
            a = (a*a)%mod;
            b/=2;
        }

        return ans;
    }

    long long inv(long long n){
        return power(n, mod - 2);
    }

    long long ncr(int n, int r, int k){
        long long ans = 1;
        r = min(r , n- r);

        for(int i=1;i<=r;i++){
            ans = (ans * (n-r+i))/i;
            if(ans >= k) return k;
        }
        return ans;
    }

    long long all(vector<int>& map, int n, int k){
        long long ans = 1;
        for(int i=0;i<26;i++){
            if(map[i] > 0){
                ans = ans * ncr(n, map[i],k);
                n -= map[i];
            }

            if(ans >= k) return k;
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        string ans = "";
        int n = s.size()/2;

        fact.push_back(1);
        infact.push_back(1);

        for(int i=1;i<=n;i++){
            fact.push_back((fact[i-1] * i)%mod);
            infact.push_back(inv(fact[i]));

        }


        vector<int > map(26,0);

        for(int i=0;i<n;i++){
            map[s[i] - 'a']++;
        }

        if(all(map,n,k) < k) return ans;
        

        for(int i=0;i<n;i++){
            for(char c = 'a';c<='z';c++){
                if(map[c - 'a'] > 0){
                    map[c - 'a']--;

                    long long hold = all(map,n-i -1,k);

                    if(hold >= k){
                        ans.push_back(c);
                        break;
                    }
                    else{
                        k -= hold;
                        map[c-'a']++;
                    }
                }
            }
        }

        if(s.size()%2 == 1) ans.push_back(s[n]);

        for(int i=n-1;i>=0;i--) ans.push_back(ans[i]);

        return ans;
    }
};