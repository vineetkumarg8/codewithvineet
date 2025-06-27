#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<int, int> findMissingAndRepeatedValue(const vector<int> &Arr) {
    int n = Arr.size();
    int missing = -1, repeat = -1;

    unordered_map<int, int> freq;
    for (int num : Arr) {
        freq[num]++;
    }

    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0)
            missing = i;
        else if (freq[i] == 2)
            repeat = i;
    }

    return {missing, repeat};
}

int main() {
    vector<int> Arr = {5, 4, 3, 1, 1};
    auto [missing, repeat] = findMissingAndRepeatedValue(Arr);
    cout << "Missing Number: " << missing << endl;
    cout << "Repeating Number: " << repeat << endl;
    return 0;
}
//T.C - O(n) for loop + O(n) for unordered_map loop -> O(n) 
//S.C - O(n) for storing (key,value) pair




//Optimized Approach with O(1)Space complexity.
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findMissingAndRepeating(vector<int>& arr) {
    int n = arr.size();
    int repeating = -1, missing = -1;

    // Step 1: Mark visited indices
    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1;
        if (arr[index] < 0) {
            repeating = abs(arr[i]);
        } else {
            arr[index] = -arr[index];
        }
    }

    // Step 2: Find the missing number
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    return {repeating, missing};
}

int main() {
    vector<int> arr = {5, 4, 3, 1, 1};
    auto [repeating, missing] = findMissingAndRepeating(arr);
    cout << "Repeating Number: " << repeating << endl;
    cout << "Missing Number: " << missing << endl;
    return 0;
}
