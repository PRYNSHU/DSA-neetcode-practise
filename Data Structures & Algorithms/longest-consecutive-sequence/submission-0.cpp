class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // via sorting algorithm
        if(nums.size() == 0)
            return 0;

        sort(nums.begin() , nums.end());

        int maxlen = 1;
        int len = 1;
        
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] + 1 == nums[i+1]) {
                len++;
                maxlen = max(len, maxlen);
            }else if(nums[i] == nums[i+1]) {
                continue;
            }else {
                len = 1;
            }
        }
        return maxlen;
    }
};
