// [Naive Approach] Concatenate and Sort – O((n1 + n2) log(n1 + n2)) time and O(1) space
// This approach involves two key steps: first, combining elements from two separate arrays into a third result array, and then sorting the result array. 

// Since it requires sorting the entire merged array, resulting in a time complexity of O((n1 + n2) log(n1 + n2)), where n is the total number of elements.

#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>& arr1, vector<int>& arr2, 
                                    vector<int>& arr3) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0, k = 0;

    // Traverse arr1 and insert its elements into arr3
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }

    // Traverse arr2 and insert its elements into arr3
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }

    // Sort the entire arr3
    sort(arr3.begin(), arr3.end());
}

// Driver code
int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    vector<int> arr3(arr1.size() + arr2.size());

    mergeArrays(arr1, arr2, arr3);

    for (int i = 0; i < arr3.size(); i++)
        cout << arr3[i] << " ";

    return 0;
}



// [Expected Approach] Using Merge of Merge Sort O(n1 + n2) time and O(n1 + n2) space
// The idea is to use Merge function of Merge sort. 


// Create an array arr3[] of size n1 + n2.
// Simultaneously traverse arr1[] and arr2[]. 
// Pick smaller of current elements in arr1[] and arr2[], copy this smaller element to next position in arr3[] and move ahead in arr3[] and the array whose element is picked.
// If there are remaining elements in arr1[] or arr2[], copy them also in arr3[].

#include <iostream>
#include <vector>
using namespace std;

// Merge ar1[0..n1-1] and ar2[0..n2-1] into ar3
void mergeArrays(vector<int>& ar1, vector<int>& ar2, 
                               vector<int>& ar3) {
    int i = 0, j = 0, k = 0;
    int n1 = ar1.size();
    int n2 = ar2.size();

    while (i < n1 && j < n2) {
      
        // Pick smaller of the two current
        // elements and move ahead in the
        // array of the picked element
        if (ar1[i] < ar2[j])
            ar3[k++] = ar1[i++];
        else
            ar3[k++] = ar2[j++];
    }

    // if there are remaining elements of
    // the first array, move them
    while (i < n1)
        ar3[k++] = ar1[i++];

    // Else if there are remaining elements of
    // the second array, move them
    while (j < n2)
        ar3[k++] = ar2[j++];
}

// Driver code
int main() {
    vector<int> ar1 = {1, 3, 5, 7};
    vector<int> ar2 = {2, 4, 6, 8};
    vector<int> ar3(ar1.size() + ar2.size());

    mergeArrays(ar1, ar2, ar3);
  
    for (int i = 0; i < ar3.size(); i++)
        cout << ar3[i] << " ";

    return 0;
}
