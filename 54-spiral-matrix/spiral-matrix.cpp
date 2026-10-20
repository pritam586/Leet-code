class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        int srow = 0;
        int erow = m-1;
        int scol = 0;
        int ecol = n-1;
        vector<int> ans;
      while(srow<=erow && scol<=ecol){
        // top
        for(int i = scol ; i<=ecol ; i++){
             ans.push_back(mat[srow][i]);
        }

        //right
        for(int j =srow+1 ;j<=erow ;j++ ){
            ans.push_back(mat[j][ecol]);
        
    }
    //bottom

    for(int i=ecol-1 ; i>=scol;i--){
        if(srow==erow){
            break;
        }
        ans.push_back(mat[erow][i]);
    }
    //left
    for(int i=erow-1;i>=srow+1;i--){
         if(scol==ecol){
            break;
        }
           ans.push_back(mat[i][srow]);
    }
    srow++;
    erow--;
    scol++;
    ecol--;

    }
  return ans;
    }
};
  
