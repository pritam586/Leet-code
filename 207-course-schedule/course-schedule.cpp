class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

            for(auto it:prerequisites){
                adj[it[1]].push_back(it[0]);
            }
        

        vector<int> indegree(numCourses , 0);
        queue<int> q;
        for(int i = 0 ;i<numCourses ; i++){
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        for(int i = 0 ; i<numCourses ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int nums = 0;

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            nums++;
            for(auto it: adj[temp]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return nums == numCourses;
    }
};