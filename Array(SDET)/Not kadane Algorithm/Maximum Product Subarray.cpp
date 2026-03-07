// Real Interview Tip (Very Important)
// Before coding, say this out loud to the interviewer:
// Example for your problem:
// "Since the array contains negative numbers, the product sign can flip. So I will track both the maximum and minimum product ending at each index."

// 1st Solution Method	Idea
// Prefix + Suffix (single loop)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int prefix = 1;
        int suffix = 1;
        int ans = nums[0];

        for(int i = 0; i < n; i++){
            
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - 1 - i];

            ans = max(ans, max(prefix, suffix));
        }

        return ans;
    }
};

// 2nd solution is Best for me (Most standard interview solution)
// two pass solution

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int ans = INT_MIN;

        // Left → Right
        for(int i = 0; i < n; i++){
            prod *= nums[i];
            ans = max(ans, prod);
            if(prod == 0) prod = 1;
        }

        prod = 1;

        // Right → Left
        for(int i = n-1; i >= 0; i--){
            prod *= nums[i];
            ans = max(ans, prod);
            if(prod == 0) prod = 1;
        }

        return ans;
    }
};
