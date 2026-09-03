class Solution {
public:
    bool f(string &s,string &p,int i,int j,int &n,int &m){
        if(i==n && j==m)return true;
        if(j==m)return false;
        if(j+1<m && p[j+1]=='*'){
            for(int k=i;k<=n;k++){
                if(f(s,p,k,j+2,n,m)){
                    return true;
                }
                if(s[k]==p[j] || p[j]=='.')continue;
                break;  
            }
            return false;
        }
        else if(i==n){
            return false;
        }
        else if(p[j]=='.'){
            return f(s,p,i+1,j+1,n,m);
        }
        else if(s[i]==p[j]){
            return f(s,p,i+1,j+1,n,m);
        }
        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return f(s,p,0,0,n,m);
    }
};