int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, right = 0;
    int maxLen = 0;
    
    while (right < s.length()) {
        if (seen.find(s[right]) == seen.end()) { // if substring not found in set
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1); // update the substring length
            right++;
        } else {
            seen.erase(s[left]); // if found duplicate found 
            left++;
        }
    }
    
    return maxLen;
}
