class Solution {
public:
    
    bool numberExists(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size() - 1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return false;
    }
    
    int getFirstOccurence(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size() - 1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] < target && mid < nums.size() - 1 && nums[mid + 1] == target) {
                return mid + 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
    
    int getLastOccurence(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size() - 1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] > target && mid > 0 && nums[mid - 1] == target) {
                return mid - 1;
            } else if(nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(!numberExists(nums, target)) {
            return {-1, -1};
        }
        
        vector<int> res(2);
        
        if(nums[0] == target) {
            res[0] = 0;
        } else {
            res[0] = getFirstOccurence(nums, target);
        }
        
        if(nums[nums.size() - 1] == target) {
            res[1] = nums.size() - 1;
        } else {
            res[1] = getLastOccurence(nums, target);
        }
        
        return res;
    }
};