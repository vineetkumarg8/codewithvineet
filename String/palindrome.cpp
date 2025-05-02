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


#include <iostream>
using namespace std;

int main() {
    string str = "madam";
    bool isPalindrome = true;

    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << "Palindrome" << endl;
    else
        cout << "Not a palindrome" << endl;

    return 0;
}

