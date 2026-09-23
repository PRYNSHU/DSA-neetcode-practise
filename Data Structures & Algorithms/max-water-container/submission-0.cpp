class Solution {
public:

    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j= n-1;
        int maxarea = 0;

        while(i<j) {
            int area = min(height[i], height[j]) * (j-i);
            maxarea = max(area, maxarea);

            // find which to move i or j
            // move from which is smaller so that we can utilize max of other stick height
            if(height[i] < height[j])
                i++;
            else if(height[i] > height[j])
                j--;
            else {
                // height is equal
                i++;
                j--;
            }
        }

        return maxarea;
    }
};