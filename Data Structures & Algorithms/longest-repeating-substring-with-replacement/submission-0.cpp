class Solution {
public:

    int maxf(vector<int> &hash) {
        int maxfreq = INT_MIN;
        for(int i: hash) {
            maxfreq = max(maxfreq, i);
        }
        return maxfreq;
    }

    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int i=0, j=0;
        int maxfreq = 0;
        vector<int> hash(27,0);

        while(i<=j && j<s.length()){ 
            // freq check at run time
            hash[s[j] - 'A']++;
            maxfreq = max(maxfreq, hash[s[j] - 'A']);
            
            // check the valueLeftToChange
            int change = j-i+1 - maxfreq;
            if(change <= k) {
                // means the current subs can add all or less k elements
                maxlen = max(maxlen, j-i+1);
            }else {
                // some elements are extra
                while((j-i+1 - maxfreq) > k) {
                    // reduce that element count by 1 from hash
                    hash[s[i] - 'A']--;
                    i++;
                    // recheck the maxfreq
                    maxfreq = maxf(hash);
                }
            }
            j++;
        }

        return maxlen;
    }

        // brute force 
    // int characterReplacement(string s, int k) {

    //     // find all the subarray, and maxfreq in each subarray and subs by len of that array and then check less than k or not.
    //     int maxlen = 0;
    //     int n = s.length();
    //     for(int i=0; i<n; i++) {
    //         vector<int> hash(27, 0);
    //         int maxfreq = 0;

    //         for(int j=i; j<n; j++) {
    //             hash[s[j] - 'A']++;
    //             maxfreq = max(maxfreq, hash[s[j] - 'A']);
    //             int leftvaluetochange = j-i+1 - maxfreq;
    //             if(leftvaluetochange <= k) {
    //                 // if the remaining value are less or equal to k then 
    //                 // only consider the lenghth of substring
    //                 maxlen = max(maxlen , j-i+1);
    //             }else
    //                 break;

    //         }
    //     }

    //     return maxlen;
    // }
};