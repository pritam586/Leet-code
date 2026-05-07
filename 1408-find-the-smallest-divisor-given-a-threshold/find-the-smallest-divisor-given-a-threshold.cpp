class Solution {
public:
    bool isPossible(vector<int>& nums, int limit , int threshold){
        int count = 0;
        for(int i = 0  ; i < nums.size() ; i++){
            count+= ceil((double)nums[i] / (double)limit);
        }
        if(count<=threshold) return true;
        else return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high;
        int maxi=INT_MIN;

        for(int i =0 ; i<nums.size() ; i++){
            maxi = max(maxi , nums[i]);
        }
        high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(nums , mid , threshold)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};