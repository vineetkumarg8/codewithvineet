vector<int> minAnd2ndMin(vector<int> &arr) {
        int min2=INT_MAX;
        
        if(arr.size()<2){
            return{-1};
        }
        int min1=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]<min1){
                min2=min1;    
                min1=arr[i];
            }
            else if (arr[i] > min1 && arr[i] < min2) {
            min2 = arr[i];
            }
        }
        if(min2==INT_MAX) return {-1};
        return {min1,min2};
    }

// Time and Space Complexity:
// Complexity	Value
// Time Complexity	O(n) — One pass through array
// Space Complexity	O(1) — Only two extra variables

#include <vector>
#include <queue>
using namespace std;

vector<int> minAnd2ndMin(vector<int> &arr) {
    if (arr.size() < 2) {
        return {-1, -1};
    }

    priority_queue<int, vector<int>, greater<int>> minheap;

    for (int i : arr) {
        minheap.push(i);
    }

    int firstMin = minheap.top();
    minheap.pop();

    // Skip all duplicates of the minimum
    while (!minheap.empty() && minheap.top() == firstMin) {
        minheap.pop();
    }

    if (minheap.empty()) {
        return {-1, -1}; // No second minimum
    }

    int secondMin = minheap.top();
    return {firstMin, secondMin};
}

// Time and Space Complexity
// Complexity	Value	Notes
// Time Complexity	O(n log n)	due to heap insertions
// Space Complexity	O(n)	heap stores all elements
