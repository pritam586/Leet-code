class Solution {
public:
    void calcom(int n, int k ,vector<vector<int>>& ans , vector<int> &com , int idx ){
        if(com.size() == k){
            ans.push_back(com);
            return;
        }
        for(int i = idx; i <=n ; i++){
            com.push_back(i);
            calcom(n , k , ans, com , i+1);
             com.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> com;
        calcom(n , k , ans, com , 1);
        return ans;
    }
};