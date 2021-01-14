/*

- In order to compute the total water that all the bars can trap,
  it makes sense to compute the amount of water each bar can trap
  and add them up.
  
- In order to compute this, for every bar we find the heights of the
  tallest bars on its left and its right (max_left, max_right).
  We then take the minimum of these two values and if the minimum is
  greater than the current bar's height, then the amount of water it
  can trap is equal to : min(max_left, max_right) - cur_height.
  If the minimum value is less than the current height, or if the bar
  is at the left or right extreme position, it cannot store any water.
  
- Generally a brute force implementation of this approach would take
  O(n^2) time and O(1) space.
  
- However, we can speed up our solution using dynamic programming.
  Essentially we use two arrays -> dpl[] and dpr[], 
  where dpl[i] represents the maximum height for all bars upto i from
  the left side
  and dpr[i] represents the maximum height for all bars upto i from
  the right side
  Important : We compute dpl[i + 1] as max(dpl[i], height[i + 1])
              We compute dpr[i - 1] as max(dpl[i], height[i - 1])
  After computing the values of these two arrays, we can apply our
  previously formulated logic to compute the amounts for each bar
  
- This solution brings down the time complexity to O(n) but increase the
  space complexity to O(n) as well.

*/


class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() < 3) {
            return 0;
        }
        
        vector<int> dpl(height.size());
        vector<int> dpr(height.size());
        
        dpl[0] = height[0];
        dpr[dpr.size() - 1] = height[height.size() - 1];
        
        for(size_t i = 1; i < height.size(); ++i) {
            dpl[i] = max(dpl[i - 1], height[i]);
            dpr[height.size() - i - 1] = max(dpr[height.size() - i], height[height.size() - i - 1]);
        }
        
        int amt = 0;
        
        for(size_t i = 1; i < height.size() - 1; ++i) {
            int minVal = min(dpl[i - 1], dpr[i + 1]);
            if(minVal > height[i]) {
                amt += minVal - height[i];
            }
        }
        
        return amt;
    }
};