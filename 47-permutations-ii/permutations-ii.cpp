class Solution {
public:
     void calper(vector<int>& nums , vector<vector<int>> &ans , int idx){
        if(idx == nums.size()){
           if (find(ans.begin(), ans.end(), nums) == ans.end()) {
                ans.push_back(nums);
            }
            return;
        }
        for(int i =idx ; i<nums.size();i++){
            swap(nums[idx],nums[i]);
            calper(nums,ans ,idx+1);
             swap(nums[idx],nums[i]);
        }
     }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
          vector<vector<int>> ans;

          calper(nums , ans , 0);

          return ans;
    }
};