char firstRep(string s) {
    int n = s.size();
    unordered_map<char,int>mp;
    for(char c:s)
    {
        mp[c]++;
    }
    for(char c:s){
        if(mp[c]>1){
            return c;
        }
    }
    return '#';

// Time Complexity:
// First loop: iterates over s once — O(n)

// Second loop: iterates over s again — O(n)

// Each unordered_map operation (insert, access) is on average O(1)

// Total time complexity:
// O(n) + O(n) = O(n)

// Space Complexity:
// unordered_map<char,int> mp stores counts for unique characters.

// Maximum unique characters in string = size of character set (e.g., ASCII = 256, Unicode can be more).

// In worst case (all characters distinct), space = O(k), where k is the size of the character set or number of unique chars.

// Usually, O(n) if all characters are unique.
