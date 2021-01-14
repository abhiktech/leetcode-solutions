class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int max = 0;
        
        int low = 0, high = height.size() - 1;
        
        while(low < high) {
            
            if(min(height[low], height[high]) * (high - low) > max) {
                max = min(height[low], height[high]) * (high - low);
            }
            
            if(height[low] < height[high]) {
                ++low;
            } else {
                --high;
            }
        }
        
        return max;
    }
};