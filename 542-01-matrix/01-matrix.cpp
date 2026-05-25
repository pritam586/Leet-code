class Solution {
public:
   void bfs(queue<pair<pair<int , int> , int>> q,
         vector<vector<int>> &visited,
         vector<vector<int>>& ans,
         int n ,
         int m,
         vector<vector<int>>& mat){

    int delr[4] = {0 , 1 , 0 , -1};
    int delc[4] = {1 , 0 , -1 , 0};

    while(!q.empty()){

        int r = q.front().first.first;
        int c = q.front().first.second;
        int val = q.front().second;

        q.pop();

        ans[r][c] = val;

        for(int i = 0 ; i < 4 ; i++){

            int calr = r + delr[i];
            int calc = c + delc[i];

            if(calr>=0 && calc>=0 && calr<n && calc<m
               && visited[calr][calc]==0
               && mat[calr][calc]==1){

                visited[calr][calc] = 1;

                q.push({{calr , calc} , val+1});
            }
        }
    }
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int , int> , int>> q;

        vector<vector<int>> visited(n , vector<int>(m , 0));

        vector<vector<int>> ans(n , vector<int>(m , 0));

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(mat[i][j]==0){
                    q.push({{i , j} , 0});
                    visited[i][j]=1;
                }
            }
        }
        bfs(q , visited , ans , n , m , mat);
        return ans;

    }
};