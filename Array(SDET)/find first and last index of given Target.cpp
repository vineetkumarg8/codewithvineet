arr = [1,2,3,3,3,4,5,6] , T = 3

int n = arr.size();
int F=-1,L=-1;

for(int i=0;i<n;i++){
  if(arr[i] == T){
    if(F==-1){
       F = i;
    }
       L=i;
    }
  }
return {F,L};
// T.C = O(n) 

#include <iostream>
#include <vector>

using namespace std;

vector<int> findFirstAndLastPosition(vector<int>& nums, int target) {
    int first = -1, last = -1;

    // Find first occurrence
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target) {
            low = mid + 1;
        } else {
            if (nums[mid] == target) first = mid;
            high = mid - 1;
        }
    }

    // Find last occurrence
    low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) {
            high = mid - 1;
        } else {
            if (nums[mid] == target) last = mid;
            low = mid + 1;
        }
    }

    return {first, last};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = findFirstAndLastPosition(nums, target);
    cout << "First index: " << result[0] << ", Last index: " << result[1] << endl;

    return 0;
}

