void moveRepeatsToEnd(vector<int>& arr) {
    unordered_map<int, int> freq;

    // Count frequency of each element
    for (int num : arr) {
        freq[num]++;
    }

    int n = arr.size();
    int index = 0;

    // First, place non-repeating elements at the beginning
    for (int i = 0; i < n; ++i) {
        if (freq[arr[i]] == 1) {
            arr[index++] = arr[i];
        }
    }

    // Then, place repeating elements at the end
    for (int i = 0; i < n; ++i) {
        if (freq[arr[i]] > 1) {
            arr[index++] = arr[i];
        }
    }
}
