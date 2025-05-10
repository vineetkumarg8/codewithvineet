// Approach 1: 
// The given problem can be solved using the following steps :
// Create a vector newArr to store only positive elements.
// Now traverse the array arr, and push positive element in newArr.
// Return newArr as the answer.
void removeNegative(vector<int>& arr)
{
    vector<int> newArr;
 
    for (auto x : arr) {
        if (x >= 0) {
            newArr.push_back(x);
        }
    }
 
    for (auto x : newArr) {
        cout << x << ' ';
    }
}
// Time Complexity: O(N)
// Auxiliary Space: O(N)


// Approach 2: Using two pointers
// This approach uses two pointers, one to iterate over the array and another to keep track of the next index to place a non-negative number.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = { 2, 5, -6, 0, -1, 7, -9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int pos = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] >= 0)
		{
			arr[pos] = arr[i];
			pos++;
		}
	}
	
	// Printing the updated array without negatives
	for(int i = 0; i < pos; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)
