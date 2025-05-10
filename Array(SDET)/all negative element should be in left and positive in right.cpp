// 🧠 Memory Trick:
// Scan left to right.
// If you find a negative, "bubble" it left over the positives — like in insertion sort.
// Use only one loop and one inner check.


// 🧠 Explanation (Step-by-step):
// j tracks the position where the next negative number should go.
// Every time a negative number is found, it's swapped with the element at index j, then j is incremented.
// This pushes all negatives to the front and positives to the end.
// Order of elements is not preserved.

void moveNegativesLeftStable(int arr[], int n) {
    // Rule: when you see a negative, shift it left until it's next to earlier negatives
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            int j = i;
            // Push current negative left while previous is positive
            while (j > 0 && arr[j - 1] >= 0) {
                swap(arr[j], arr[j - 1]);
                j--;  // Continue shifting
            }
        }
    }
}

// Complexity
// Time Complexity: O(N^2), As we are using a nested loop which takes N2 time in the worst case.
// Auxiliary Space: O(1), As we are not using any extra space.



// Best Solution by maintaining order
void Rearrange(int arr[], int n) {
        vector<int>Neg;
        vector<int>Pos;
    
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                Neg.push_back(arr[i]);
            }
            else Pos.push_back(arr[i]);
        }
        
        int idx=0;
        for(int i=0;i<Neg.size();i++){
            arr[idx++]=Neg[i];
        }
        for(int i=0;i<Pos.size();i++){
            arr[idx++]=Pos[i];
        }
    }

// Complexity
// TC: O(n)
//SC: O(n) (because of extra space for Neg and Pos)
