class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if(arr.size() < 3) {
            return false;
        }
        
        int index = 0;
        while(index < arr.size() - 1 && arr[index] < arr[index + 1]) {
            ++index;
        }
        
        if(index == 0 || index == arr.size() - 1 || arr[index] == arr[index + 1]) {
            return false;
        }
        
        while(index < arr.size() - 1 && arr[index] > arr[index + 1]) {
            ++index;
        }
        
        return index == arr.size() - 1;
        
    }
};