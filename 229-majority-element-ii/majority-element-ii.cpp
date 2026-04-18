class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority = n/3;
        unordered_map<int , int> mp;
        vector<int> ans;

        for(int i = 0 ; i<nums.size()  ; i++){
            mp[nums[i]]++;
        }


        for(auto i: mp){
           if(i.second>majority){
            ans.push_back(i.first);
           }
        }

        return ans;
    }
};