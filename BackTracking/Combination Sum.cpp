class Solution {
public:

set<vector<int>> s;

    void getAllCombinations(vector<int>&combinations,vector<vector<int>>&ans,int idx,vector<int>& candidates , int target ,int n){

        if(idx == n || target<0){
            return;
        }
        if(target==0){
            if(s.find(combinations) == s.end()){
                ans.push_back(combinations);
                s.insert(combinations);
            }
            return;
        }

        combinations.push_back(candidates[idx]);
        //SingleInclusiveSum
        getAllCombinations(combinations,ans,idx+1,candidates,target-candidates[idx],n);
        //MultipleExclusiveSum
        getAllCombinations(combinations,ans,idx,candidates,target-candidates[idx],n);
        combinations.pop_back();
        //ExclusiveSum
        getAllCombinations(combinations,ans,idx+1,candidates,target,n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>combinations;
        vector<vector<int>>ans;  

        getAllCombinations(combinations,ans,0,candidates,target,n);
        return ans;
    }
};

| Type      | Complexity                  |
| --------- | --------------------------- |
| **Time**  | ❌ ( O(3^n * k log M) ) |
| **Space** | ❌ ( O(2^n * k) )        |

