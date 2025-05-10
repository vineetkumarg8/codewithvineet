class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>maxheap;
        for(auto i:nums){
            maxheap.push(i);
        }
        while(maxheap.size()>k){
            maxheap.pop();
        }
        return maxheap.top();;
    }
};
