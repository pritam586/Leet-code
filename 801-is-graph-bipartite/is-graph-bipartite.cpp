class Solution {
    private:
    bool dfs(int node , int col ,vector<vector<int>>& graph , int color[] ){
        color[node] = col;

        for(auto adj:graph[node]){
            if(color[adj]==-1){
            if(dfs(adj , !col, graph , color)==false) return false;}
            else if(color[adj]==col) return false;
        }
        return true;
    }
public:

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        for(int i = 0 ; i<n ; i++) color[i] = -1;

        for(int i =0  ; i<n ; i++){
            if(color[i]==-1){
            if(dfs(i , 0 , graph , color)==false) return false;}
        }

        return true;
    }
};