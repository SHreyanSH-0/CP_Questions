class Solution {
public:
    int maximumGap(string skill, string station) {
        int ans = 0;

        // abczzc
        // j
        // abc
        // i

        /*

            indices = {
                0: 0
                1: 1
                2: 2,5
                .
                .
                .
                25: 3,4
            
            }


        */

        // abczzc
        //  j
        // abc
        //  i

        // [0,1,2]
        // [0,1,5]


        // aaaa
        // aa

        // [0,1]
        // [2,3]

        // if i'm at ind j in station 
        // if the index at skill is greate than the can[j] ie can[j] < i, i cant make an assignment


        int n = skill.size();
        int m = station.size();

        vector<int> pre(n+1,-1), post(n+1,-1);


        int i = 0;

        for(int j=0;j<m;j++){
            if(i<n && skill[i] == station[j]){
                pre[i++] = j;
            }
        }

        i = n-1;
        for(int j=m-1;j>=0;j--){
            if(i>=0 && skill[i] == station[j]){
                post[i--] = j;
            }
        }


        for(int i=1;i<n;i++){
            ans = max(ans, max(post[i] - pre[i-1], max(pre[i] - pre[i-1], post[i] - post[i-1])));
        }

        return ans;
    }
};