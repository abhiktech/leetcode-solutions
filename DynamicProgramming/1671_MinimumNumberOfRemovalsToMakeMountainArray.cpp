class Solution {
public:
    
    /*
    - Our objective in this problem is to find the minimum number of removals
      needed to make a mountain array. In other words, we are trying to form
      a mountain array with the most elements possible.
      
    - A mountain array is a special kind of array where there is a maximum element
      somewhere in the array such that all elements before it are in a strictly increasing
      sequence and all elements after it are in a strictly decreasing sequence.
      
    - The minimum size of a mountain array has to be 3.
    
    - In this question, it is guaranteed that it is possible to form a mountain array.
      Note : The given array itself could also be a mountain array.
      
    - Our strategy to solve this problem should be to treat every element of the array as the
      "peak" of a mountain subsequence.
      
    - For every "peak", we do two things : 
        a) Calculate the length of the longest increasing subsequence for elements
           less than it and to the left of it.
        b) Calculate the length of the longest decreasing subsequence for elements
           less than it and to the right of it.
           
        Note : These longest subsequences can be computed using Dynamic Programming.
               Let dpl[cur] represent the length of the longest increasing subsequence 
               for elements less than nums[cur] and have index positions < cur (are to its left).
               To compute dpl[cur] we obtain the max value "dpl[j]" such that nums[j] < nums[cur]
               and dpl[j] is the maximum value in dpl[] for nums[] values < nums[cur] and to the
               left of cur. We also add one to our result.
               
               We apply the same logic (with a few tweaks) for part b) and store the
               results in dpr[].
      
    - Finally after computing dpl[] and dpr[], we say that the peak of our largest mountain
      array is placed at index "maxIndex" where dpl[maxIndex] + dpr[maxIndex] is maximum.
      Note : We should not consider a position where dpl[i] == 0 || dpr[i] == 0.
      
    - Our answer will be nums.size() - (dpl[maxIndex] + dpr[maxIndex] + 1)
    
    - Our solution has a O(n^2) time complexity and O(n) space complexity.
    
    */
    
    
    int minimumMountainRemovals(vector<int>& nums) {
        
        vector<int> dpl(nums.size());
        vector<int> dpr(nums.size());
        
        for(int i = 0; i < nums.size(); ++i) {
            
            int max = -1;
            
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i] && dpl[j] > max) {
                    max = dpl[j];
                }
            }
            
            if(max == -1) {
                dpl[i] = 0;
            } else {
                dpl[i] = max + 1;
            }
            
        }
        
        for(int i = nums.size() - 1; i >= 0; --i) {
            
            int max = -1;
            
            for(int j = nums.size() - 1; j > i; --j) {
                if(nums[j] < nums[i] && dpr[j] > max) {
                    max = dpr[j];
                }
            }
            
            if(max == -1) {
                dpr[i] = 0;
            } else {
                dpr[i] = max + 1;
            }
            
        }
        
        int longest = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(dpl[i] != 0 && dpr[i] != 0 && dpl[i] + dpr[i] > longest) {
                longest = dpl[i] + dpr[i];
            }
        }
        
        return (nums.size() - longest - 1);
    }
};