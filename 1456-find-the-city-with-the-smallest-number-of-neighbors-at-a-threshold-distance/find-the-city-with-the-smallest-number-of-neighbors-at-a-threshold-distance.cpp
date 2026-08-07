class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for(auto it : edges){
            int r = it[0];
            int c = it[1];
            int wt = it[2];
            mat[r][c] = wt;
            mat[c][r] = wt;
        }
        for(int i = 0 ; i<n ; i++){
            mat[i][i] = 0;
        }

        for(int k = 0 ; k<n ; k++){
            for(int i = 0 ; i<n ; i++){
                for(int j = 0 ; j<n ; j++){
                    mat[i][j] = min(mat[i][j] , mat[i][k]+mat[k][j]);
                }
            }
        }

        vector<int> reachCity(n , 0);

        for(int i = 0 ; i<n ; i++){
             int count  = 0;
            for(int j = 0 ; j<n ; j++){
               
                if(mat[i][j]<=distanceThreshold){
                    count++;
                }
            }
            reachCity[i] = count;
        }

      int city = -1;
int mini = INT_MAX;

for(int i = 0; i < n; i++) {
    if(reachCity[i] <= mini) {
        mini = reachCity[i];
        city = i;
    }
}

return city;
    }
};