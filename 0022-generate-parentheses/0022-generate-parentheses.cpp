class Solution {
public:

    void rec(vector<string> &ans, string hold, int n,int op, int clo){

        if(hold.size()==2*n){
            ans.push_back(hold);
            return;
        }

        if(op==n){
            hold.push_back(')');
            rec(ans,hold,n,op,clo+1);
        }
        else if(op==clo){
            hold.push_back('(');
            rec(ans,hold,n,op+1,clo);
        }
        else{
            hold.push_back('(');
            rec(ans,hold,n,op+1,clo);

            hold.pop_back();
            hold.push_back(')');
            rec(ans,hold,n,op,clo+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string hold = "(";
        rec(ans,hold,n,1,0);
        return ans;
    }
};