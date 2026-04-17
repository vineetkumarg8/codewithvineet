// Optimized Solution without set
class Solution {
public:
    void solve(vector<int>& candidates, int target, int idx,
               vector<int>& comb, vector<vector<int>>& ans) {
        
        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // 🔑 Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            comb.push_back(candidates[i]);

            solve(candidates, target - candidates[i], i + 1, comb, ans);

            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> comb;

        solve(candidates, target, 0, comb, ans);
        return ans;
    }
};

| Approach       | Time Complexity               | Space Complexity |
| -------------- | ----------------------------- | ---------------- |
| ❌ Mine (`set`) | (O(2^n \cdot n \cdot \log K)) | (O(2^n \cdot n)) |
| ✅ Optimized    | (O(2^n \cdot n))              | (O(2^n \cdot n)) |

// My Solution using set

class Solution {
public:

set<vector<int>>s;
void GetAllCombinations(vector<int>& candidates, int target ,int idx ,vector<int>combinations,vector<vector<int>>& ans){

if(target == 0){
    if(s.find(combinations) == s.end()){
        ans.push_back(combinations);
        s.insert(combinations);
    }
    return;
}


    if(target<0 || idx == candidates.size()){
    return;
}

    combinations.push_back(candidates[idx]);

    //With one inclusive
    GetAllCombinations(candidates,target-candidates[idx],idx+1,combinations,ans);

    combinations.pop_back();
    //with Exclusive
    GetAllCombinations(candidates,target,idx+1,combinations,ans);
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>combinations;
        vector<vector<int>>ans;

        GetAllCombinations(candidates,target,0,combinations,ans);
        return ans;
    }
};
