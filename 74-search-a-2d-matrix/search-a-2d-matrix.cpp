class Solution {
public:
    bool find(vector<vector<int>>& matrix, int target, int row){
        int n = matrix[0].size();
        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1; 
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

           
            if(matrix[mid][0] <= target && target <= matrix[mid][n - 1]){
                return find(matrix, target, mid);
            }
            else if(matrix[mid][0] > target){
                high = mid - 1; 
            }
            else{
                low = mid + 1;   
            }
        }

        return false;
    }
};