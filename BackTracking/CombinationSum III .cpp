class Solution {
public:
void GetAllCombinations(int k ,int n,vector<vector<int>>& ans ,vector<int>& combinations,int idx){
    if(k==0 && n==0){
        ans.push_back(combinations);
        return;
    }
    if(k==0 || n < 0) return;

    for(int i=idx;i<=9;i++){
        combinations.push_back(i);
        GetAllCombinations(k-1,n-i,ans,combinations,i+1);
        combinations.pop_back();
    }
}

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>combinations;
        GetAllCombinations(k, n, ans, combinations, 1);
        return ans;
    }
};


//  TC ≈ O(2⁹) (since subset generation upper bound)
//  SC ≈ O(k) (excluding output)
