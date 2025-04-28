# Without Recursion 
bool palindrome(string &s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

# with Recursion 
bool palindrome(string &s, int i, int j) {
    if (i >= j) {
        return true;
    }
    if (s[i] == s[j]) {
        return palindrome(s, i + 1, j - 1);
    }
    return false;
}

