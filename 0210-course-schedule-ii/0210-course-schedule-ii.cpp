class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inEdges(numCourses,0);

        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0;i<numCourses;i++){
            for(int j=0;j<graph[i].size();j++){
                inEdges[graph[i][j]]++;
            }
        }    

        queue<int> q;
        vector<int> s;

        for(int i=0;i<numCourses;i++){
            if(inEdges[i]==0) {
                q.push(i);
            }
        }

        while(!q.empty()){
            int ele = q.front();
            q.pop();
            s.push_back(ele);
            for(int i=0;i<graph[ele].size();i++){
                inEdges[graph[ele][i]]--;
                if(inEdges[graph[ele][i]]==0){
                    q.push(graph[ele][i]);
                }
            }
        }
        if(s.size()==numCourses)  return s;
        return {};
    }
};