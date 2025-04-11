class Solution {
    public:
    
    void dfs(int u,vector<vector<int>> &adj, 
    vector<bool> &visited,vector<int>&result){
        if(visited[u] == true) return;
        visited[u] = true;
        result.push_back(u);
        
        for(int &v : adj[u]){
            if(!visited[v]){
                dfs(v,adj,visited,result);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>adj) {
        int V = adj.size(); // get number of vertices from the size of adj
        vector<int>result;
        vector<bool> visited(V,false);
        dfs(0, adj,visited,result);
        return result;
    }
};
