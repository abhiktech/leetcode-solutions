/*
 *
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

/*

1. Find peak
2. Look for first occurence towards the peak's left
3. If not found, look for first occurence in peak's right

*/

class Solution {
public:
    
    int findPeak(MountainArray& m, const int& target, int& minIndex) {
        
        int low = 0, high = m.length() - 1;
        
        while(low <= high) {
            
            int mid = (low + high) / 2;
            
            if(mid == 0) {
                ++low;
                continue;
            } else if(mid == m.length() - 1) {
                --high;
                continue;
            }
            
            int prev = m.get(mid - 1);
            int cur = m.get(mid);
            int next = m.get(mid + 1);
            
            if(cur > prev && cur > next) {
                if(cur == target) {
                    minIndex = mid;
                }
                return mid;
            } else if(cur > prev) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            
        }
        
        return -1;
    }
    
    void findValueLeft(MountainArray& m, const int& target, int& minIndex, const int& peak) {
        
        int low = 0, high = peak - 1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            int cur = m.get(mid);
            if(cur == target) {
                minIndex = mid;
                high = mid - 1;
            } else if(cur < target) {
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        
    }
    
    void findValueRight(MountainArray& m, const int& target, int& minIndex, const int& peak) {
        
        int low = peak + 1, high = m.length() - 1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            int cur = m.get(mid);
            if(cur == target) {
                minIndex = mid;
                high = mid - 1;
            } else if(cur < target) {
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }
        
    }
    
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int minIndex = -1;
    
        int peak = findPeak(mountainArr, target, minIndex);
        
        findValueLeft(mountainArr, target, minIndex, peak);
        
        if(minIndex != -1) {
            return minIndex;
        }
        
        findValueRight(mountainArr, target, minIndex, peak);
        
        return minIndex;
    }
};
