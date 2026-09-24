class Solution {
public:
    int trap(vector<int>& height) {
        
        // two pointer approach

        // find the prefixmax and suffix max -> so that to check indivial arr[i] how much total store using right and left 

        // pref and suff
        int n = height.size();
        vector<int> prefmax(n,0);
        vector<int> suffmax(n,0);
        prefmax[0] = height[0];

        for(int i=1; i<n; i++) {
            prefmax[i] = max(prefmax[i-1], height[i]);
        }

        suffmax[n-1] = height[n-1];

        for(int i=n-2; i>=0; i--) {
            suffmax[i] =  max(suffmax[i+1], height[i]);
        }

        /// find the total areal
        int totalarea = 0;

        for(int i=0; i<n; i++) {
            
            if(height[i] < prefmax[i] && height[i] < suffmax[i]) {
                // in between
                totalarea += min(prefmax[i], suffmax[i]) - height[i];
            }
        }

        return totalarea;

    }
};
