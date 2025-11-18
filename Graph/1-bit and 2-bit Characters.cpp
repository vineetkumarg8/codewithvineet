class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // means last must be 0, 2nd last must not be 1
        int n = bits.size();
        int count = 0;

        for(int i = n-2; i >= 0; i--){
            if(bits[i] == 1){
                count++;
            }
            else {
                break;
            }

        }
        int last = n-1;

        if(count%2 == 0 && bits[last] == 0){
            return true;
        }
        return false;
    }
};
