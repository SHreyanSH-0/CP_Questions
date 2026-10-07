class Solution {
public:
    int maxi = 0;

    void rec2(string &s, int i, int n, int ct){
        if(i >= s.size()){
            if(ct == 0)
            maxi = max(maxi, n);
            return;
        }

        if(ct < 0) return ;
        if(s[i] != '(' && s[i] != ')'){
            rec2(s,i+1,n+1,ct);
            return;
        }
        int newct = s[i] == '(' ? ct + 1 : ct - 1;
        rec2(s,i+1,n+1,newct);
        rec2(s,i+1,n,ct);

        return;
    }
    void rec(set<string>&ans, string &s, int i, string &hold, int ct){
        if(i >= s.size()){
            if(ct == 0 && hold.size() == maxi) ans.insert(hold);
            return;
        }

        if(ct < 0) return ;

        if(s[i] != '(' && s[i] != ')'){
            hold.push_back(s[i]);
            rec(ans,s,i+1,hold,ct);
            hold.pop_back();
            return;
        }

        int newct = s[i] == '(' ? ct + 1 : ct - 1;
        hold.push_back(s[i]);
        rec(ans,s,i+1,hold,newct);
        hold.pop_back();
        rec(ans,s,i+1,hold,ct);

        return;
    }

    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        string hold = "",a = "";
        
        rec2(s,0,0,0);
        rec(ans,s,0,hold,0);

        vector<string> ret;

        for(auto it : ans) ret.push_back(it);
        return ret;
    }
};