class Solution {
public:
    string simplifyPath(string a) {
        int n=a.size();
        vector<string>s;
        string temp;
        for(int i=0;i<n;i++){
            if(a[i]=='/'){
                if(temp.empty())continue;
                if(temp=="."){
                    temp="";
                    continue;
                }
                if(temp==".." && s.size()>0){
                    temp="";
                    s.pop_back();
                    continue;
                }
                if(temp==".." && s.size()==0){
                    temp="";
                    continue;
                }
                s.push_back(temp);
                temp="";
                continue;
            }
            temp.push_back(a[i]);
        }
        if(temp!=""){
            if(temp=="."){
                    temp="";
            }
            else if(temp==".." && s.size()>0){
                s.pop_back();
            }
            else if(temp==".." && s.size()==0){
                temp="";
            }
            else{
                s.push_back(temp);
            }
        }      
        if(s.empty())return "/";
        string ans;
        for(int i=0;i<s.size();i++){
            ans.push_back('/');
            for(int j=0;j<s[i].size();j++){
                ans.push_back(s[i][j]);
            }       
        }
        return ans;
    }
};