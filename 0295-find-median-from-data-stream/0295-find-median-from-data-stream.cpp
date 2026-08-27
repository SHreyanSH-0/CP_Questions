class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> right; 
    priority_queue<int> left; 
    MedianFinder() {}
    
    void addNum(int num) {
        if(left.size()==0){
            left.push(num);
        }
        else if(right.size()==0){
            if(num>=left.top()){
                right.push(num);
            }
            else{
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
        else{
            if(left.size()==right.size()){
                if(num>right.top()){
                    right.push(num);
                    left.push(right.top());
                    right.pop();
                }   
                else{
                    left.push(num);
                }
            }
            else{
                if(num>right.top()){
                    right.push(num);
                }
                else{
                    left.push(num);
                    right.push(left.top());
                    left.pop();
                }
            }
        }
        
    }
    
    double findMedian() {
        double ans = 0;
        int size = left.size() + right.size();
        if(size%2==0){
            ans = (left.top() + right.top());
            ans = ans/2;
        }
        else{
            ans = left.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */