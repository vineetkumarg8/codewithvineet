//brute force
int trap(vector<int>& height) {
    int n = height.size();
    int totalWater = 0;

    for (int i = 0; i < n; i++) {
        int leftMax = 0, rightMax = 0;

        // Find max to the left of i (including i)
        for (int j = 0; j <= i; j++) {
            leftMax = max(leftMax, height[j]);
        }

        // Find max to the right of i (including i)
        for (int j = i; j < n; j++) {
            rightMax = max(rightMax, height[j]);
        }

        // Calculate trapped water at i
        totalWater += min(leftMax, rightMax) - height[i];
    }

    return totalWater;
}

//Two pointer
int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int totalWater = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                totalWater += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                totalWater += rightMax - height[right];
            }
            right--;
        }
    }

    return totalWater;
}
