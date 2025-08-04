// Input: "Aaabbc"
// Output: "a3b2c" 


#include <iostream>
#include <string>
#include <cctype> // for tolower()

using namespace std;

string compressStringOptimized(const string& input) {
    string result;
    int n = input.length();

    for (int i = 0; i < n; ) {
        char current = tolower(input[i]);  // Normalize case
        int count = 1;

        // Count consecutive characters
        while (i + 1 < n && tolower(input[i]) == tolower(input[i + 1])) {
            count++;
            i++;
        }

        result += current;
        if (count > 1) {
            result += to_string(count);
        }

        i++;
    }

    return result;
}

int main() {
    string input = "Aaabbc";
    cout << compressStringOptimized(input) << endl;  // Output: a3b2c
    return 0;
}


// Input: "aaabbc"
// Output: "a3b2c" 

#include <iostream>
#include <string>

using namespace std;

string compressPreserveCase(const string& input) {
    string result;
    int n = input.length();
    int i = 0;

    while (i < n) {
        char current = input[i];  // Preserve case
        int count = 1;

        // Count consecutive identical (case-sensitive) characters
        while (i + 1 < n && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        result += current;
        if (count > 1) {
            result += to_string(count);
        }

        i++;  // Move to the next character group
    }

    return result;
}

int main() {
    string input = "Aaabbc";
    cout << compressPreserveCase(input) << endl;  // Output: Aa2b2c
    return 0;
}


//Last round of PS Global


// | Metric               | Value  |
// | -------------------- | ------ |
// | **Time Complexity**  | `O(n)` |
// | **Space Complexity** | `O(n)` |
