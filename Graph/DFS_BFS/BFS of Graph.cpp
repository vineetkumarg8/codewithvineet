class Solution {
  public:
    void bfs(int u,vector<vector<int>> &adj, 
    vector<bool> &visited,vector<int>&result){
        queue<int>que;
        que.push(u);
        visited[u] = true;
        result.push_back(u);
        
        while(!que.empty()){
            int u=que.front();
            que.pop();
            
            for(int &v: adj[u]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size(); // get number of vertices from the size of adj
        vector<int>result;
        vector<bool> visited(V,false);
        bfs(0, adj,visited,result);
        return result;
        
    }
};
