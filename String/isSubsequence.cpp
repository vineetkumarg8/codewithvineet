//Is Subsequence using two pointers
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        int n1=s.size();
        int n2=t.size();

        while(i<n1 && j<n2){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else j++;
        }
        return i==s.size();
    }
};
