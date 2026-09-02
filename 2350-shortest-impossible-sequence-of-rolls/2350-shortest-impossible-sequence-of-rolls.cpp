class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
       set<int> s;
       int n = rolls.size();
        vector<int> hold(n+1,0);

        for(int i=n-1;i>=0;i--){
            s.insert(rolls[i]);
            if(s.size() == k){
                hold[i] = hold[i+1] + 1;
                s.clear();
            }
            else{
                hold[i] = hold[i+1];
            }
        }

        return hold[0] + 1; 
    }
};