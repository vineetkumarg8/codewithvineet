// Given an array arr, in one step you can pick one number from the beginning and the array. You have to take exactly K numbers, 
// Your score will be the sum of the numbers you have taken
// Given array arr, and number K. Return Maximum score you can obtain

// Example:-
// arr=[1,2,3,4,5,6,1]
// K=3
// Output = 12

//BruteForce

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxScore(vector<int>& arr, int k) {
    int n = arr.size();
    int max_sum = 0;

    for (int i = 0; i <= k; i++) { //i.e - i<=3
        int sum = 0;

        // Take i elements from front
        for (int j = 0; j < i; j++) { //i.e - j<i -> j<3
            sum += arr[j];
        }

        // Take (k - i) elements from back
        for (int j = 0; j < k - i; j++) { //
            sum += arr[n - 1 - j];
        }

        max_sum = max(max_sum, sum);
    }

    return max_sum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << maxScoreBruteForce(arr, k);  // Output: 12
    return 0;
}

// 🕐 Time Complexity:
// O(K²) – For each possible split (from 0 to k), we loop again to calculate sum.

//OPtimize Approach (Sliding Window)

// Example:-
// arr=[1,2,3,4,5,6,1]
// K=3
// Output = 12
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxScore(vector<int>& arr, int k) {
    int n = arr.size();
    int total = 0;

    // Initial: take first k elements
    for (int i = 0; i < k; ++i) {
        total += arr[i]; //total=6
    }

    int max_sum = total; //max_sum=6

    // Try replacing front elements with back ones
    for (int i = 1; i <= k; ++i) {
        total = total - arr[k - i] + arr[n - i]; 
       // remove from front, add from back -> total  = 6-3+1=4,total = 4-2+6=8,total = 8-1+5=12 
        max_sum = max(max_sum, total); //(6,12)
    }

    return max_sum; //12
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << maxScore(arr, k);  // Output: 12
    return 0;
}




//technical round 1 hiring for amazon SDE1 (BU consult)
