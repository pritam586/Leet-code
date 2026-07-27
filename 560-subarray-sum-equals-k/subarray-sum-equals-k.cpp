class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        mp[0] =1;
        int count= 0 ;
        int prefixSum  = 0;
        for(int i =0 ; i<nums.size() ; i++){
            prefixSum  +=  nums[i];
            int min = prefixSum-k;
            count+=mp[min];
            mp[prefixSum]+=1;
        }
        return count;
    }
};