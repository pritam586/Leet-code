class Solution {
public:
    bool possible(vector<int> nums , int k , int minSum){
        int possibleSubarray = 1;
        int sum = 0;
        for(int i =0 ; i< nums.size() ; i++){
            sum+=nums[i];
            if(minSum<sum){
                possibleSubarray++;
                sum = nums[i];
            }
        }
        return possibleSubarray<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN;
        int high =0;
        for(int i =0  ; i<nums.size() ; i++){
            low = max(low , nums[i]);
            high += nums[i];
        }

        while(low<=high){
            int mid = (low+high)/2;
            if(possible(nums, k , mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};