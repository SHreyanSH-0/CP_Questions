class Solution {
public:

    bool lies(int x, int y, vector<int>&rect){
        return (x > rect[0] && x < rect[2] && y>rect[1] && y< rect[3]); 
    }

    bool check(vector<int>& rec1, vector<int>& rec2){
        for(int i=0;i<4;i+=2){
            for(int j=1;j<4;j+=2){
                int x = rec1[i];
                int y = rec1[j];

                if(lies(x,y,rec2)) return true;
            }
        }
        return false;
    }

    bool check2(vector<int>& rec1, vector<int>& rec2){
        int i = 0;
        int x1 = rec1[i];
        int y1 = rec1[i+1];
        i+=2;
        int x2 = rec1[i];
        int y2 = rec1[i+1];
        i = 0;
        int x3 = rec2[i];
        int y3 = rec2[i+1];
        i+=2;
        int x4 = rec2[i];
        int y4 = rec2[i+1];
        

        if(x3 >= x1 && x4 <= x2 && y3 <= y1 && y4 >= y2) return true; 

        return false;
    }

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return check(rec1,rec2) || check(rec2,rec1) || check2(rec1,rec2) || check2(rec2,rec1);
    }
};