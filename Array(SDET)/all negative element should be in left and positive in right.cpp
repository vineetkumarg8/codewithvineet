// 🧠 Memory Trick:
// Scan left to right.

// If you find a negative, "bubble" it left over the positives — like in insertion sort.

// Use only one loop and one inner check.
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
