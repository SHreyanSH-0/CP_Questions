class Solution {
public:

    int p1 = 31, p2 = 37;

    int mod = 1e9 + 7;

    bool isPal(string &s){
        int i =0, j = s.size() - 1;
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }

    long long power(long long a, long long b){
        long long ans = 1;
        while(b>0){
            if(b %2 == 1) ans = (ans * a)%mod;
            a = (a * a)%mod;
            b/=2;
        }
        return ans;
    }

    long long inv(long long n){
        return power(n,mod - 2);
    }

    string shortestPalindrome(string s) {
        if(isPal(s)) return s;
        string ans = "";
        int idx = s.size() - 1;

        long long hash1 = 0, hash2 = 0;
        int n = s.size();

        vector<long long> pref1(n), pref2(n), pref3(n), pref4(n);

        long long m1 = 1, m2 = 1;

        for(int i=0;i<n;i++){
            hash1 = (hash1 + (s[i]*m1)%mod)%mod;
            hash2 = (hash2 + (s[i]*m2)%mod)%mod;

            pref1[i] = hash1;
            pref2[i] = hash2;

            m1 = (m1*p1)%mod;
            m2 = (m2*p2)%mod;
        }
        long long hash3 = 0, hash4 = 0;
        m1 = m2 = 1;
        for(int i=n-1;i>=0;i--){
            hash3 = (hash3 + (s[i]*m1)%mod)%mod;
            hash4 = (hash4 + (s[i]*m2)%mod)%mod;

            pref3[i] = hash3;
            pref4[i] = hash4;

            m1 = (m1*p1)%mod;
            m2 = (m2*p2)%mod;
        }


        int len = n + 1;

        vector<long long> a1(2*n+1), a2(2*n+1);
        
        a1[0] = a2[0] = 1;

        for(int i=1;i<=2*n;i++){
            a1[i] = (a1[i-1] * p1)%mod;
            a2[i] = (a2[i-1] * p2)%mod;
        }

        int i;
        for(i=n-1;i>0;i--){ 

            long long h1,h2,h3,h4;

            h1 = h2 = h3 = h4 = 0;

            // abcd =>  d abcd 5
            // i----- ----------i-----
            // cout<<len<< " ";
            if(len%2 == 1){
                int taken = n - i;
                int toTake = len/2 - taken - 1;

                h1 = (pref3[i])%mod;
                h2 = (pref4[i])%mod;

                if(toTake >=0){
                    h1 = (h1 + (pref1[toTake] * a1[taken])%mod)%mod;
                    h2 = (h2 + (pref2[toTake] * a2[taken])%mod)%mod;
                }

                // cout<<toTake<<endl;
                toTake+=2;

                h3 = (pref3[toTake] + mod )%mod;
                h4 = (pref4[toTake] + mod )%mod;
            }
            else{
                int taken = n - i;
                int toTake = len/2 - taken -1;

                h1 = (pref3[i] + mod )%mod;
                h2 = (pref4[i] + mod )%mod;

                if(toTake >=0){
                    h1 = (h1 + (pref1[toTake] * a1[taken])%mod)%mod;
                    h2 = (h2 + (pref2[toTake] * a2[taken])%mod)%mod;
                }

                toTake++;
                h3 = (pref3[toTake] + mod )%mod;
                h4 = (pref4[toTake] + mod )%mod;

                // cout<<toTake<<endl;
            }
            // cout<<i <<" "<< h1<<" "<< h2<<" "<< h3<<" "<< h4<<" "<<endl;
            if(h1 == h3 && h2 == h4){
                for(int j=n-1;j>=i;j--) ans.push_back(s[j]);
                for(int j=0;j<n;j++) ans.push_back(s[j]);

                return ans;
            }

            len++;
        }
        return s + s;
    }
};