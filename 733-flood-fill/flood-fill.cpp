class Solution {
public:
    void dfs(int row ,int col , vector<vector<int>>& ans, vector<vector<int>>& image ,int newCol , int delRow[] , int delCol[] , int initCor){
        ans[row][col] =  newCol;
        int n=image.size();
        int m = image[0].size();
        for(int i = 0 ; i<4 ; i++){
            int nrow = row + delRow[i];
            int ncol  = col + delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == initCor && ans[nrow][ncol]!=newCol){
                 dfs(nrow , ncol , ans , image , newCol , delRow  , delCol ,initCor );
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initCor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1 , 0 , +1 , 0};
        int delCol[] = {0  , +1 , 0 , -1};
        dfs(sr , sc , ans , image , color , delRow  , delCol ,initCor );
        return ans;
    }
};