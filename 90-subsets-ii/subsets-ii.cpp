class Solution {
public:
    void subset(vector<int>& nums , vector<vector<int>>& ans ,  vector<int>& subsetValue , int index){
        if(index == nums.size()){
            if (find(ans.begin(), ans.end(), subsetValue) == ans.end()) {
                ans.push_back(subsetValue);
            }
           
            return ;
        }
        subsetValue.push_back(nums[index]);
        subset(nums ,ans , subsetValue , index+1 );
        subsetValue.pop_back();

         subset(nums ,ans , subsetValue , index+1 );

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subsetValue;
        sort(nums.begin(), nums.end());
        subset(nums , ans , subsetValue , 0);

        return ans;
    }
};