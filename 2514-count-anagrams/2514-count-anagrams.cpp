class Solution {
public:
    long long mod = 1e9 + 7;

    vector<long long> infact, fact;

    Solution(){
        infact.push_back(1);
        fact.push_back(1);
        for(int i=1;i<=1e5;i++){
            fact.push_back((fact[i-1]*i)%mod);
            infact.push_back(inv(fact[i]));
        }
    }

    long long  power(long long a, long long b){
        long long ans = 1;
        while( b > 0){
            if(b%2 == 1) ans = (ans * a)%mod;
            a = (a*a)%mod;
            b/=2;
        }
        return ans;
    }

    long long inv(long long n){
        return power(n,mod - 2);
    }

    long long fun(string &temp, vector<long long>&infact, vector<long long>&fact){
        vector<int> freq(26,0);

        for(int i=0;i<temp.size();i++){
            freq[temp[i] - 'a']++;
        }

        long long ans = fact[temp.size()];
        for(int i=0;i<26;i++){
            ans = (ans * infact[freq[i]])%mod;
        }


        return ans;
    }

    int countAnagrams(string s) {
        string temp = "";
        long long ans = 1;

        

        for(int i=0;i<s.size();i++){
            if(s[i] == ' ')
                ans = (ans * fun(temp,infact,fact))%mod , temp = "";
            else 
                temp.push_back(s[i]);
        }

        ans = (ans * fun(temp,infact,fact))%mod;

        return ans;
    }
};