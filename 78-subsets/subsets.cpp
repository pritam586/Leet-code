class Solution {
public:
    void calsubset(vector<int>& nums, vector<int>& subsetValue, vector<vector<int>> &ans, int index){
       
        if(index == nums.size()){
            ans.push_back(subsetValue);
            return;
        }

        subsetValue.push_back(nums[index]);
        calsubset(nums, subsetValue, ans, index+1);
        subsetValue.pop_back();

        calsubset(nums, subsetValue, ans, index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subsetValue;
        calsubset(nums, subsetValue, ans, 0);
        return ans;
    }
};