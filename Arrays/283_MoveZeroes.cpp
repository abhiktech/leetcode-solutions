class Solution {
public:
    
    void swap(int& val1, int& val2) {
        int temp = val1;
        val1 = val2;
        val2 = temp;
    }
    
    void findFirstZero(vector<int>& nums, int& firstZero) {
        while(nums[firstZero] != 0 && firstZero < nums.size()) {
            ++firstZero;
        }
    }
    
    void moveZeroes(vector<int>& nums) {
        
        int index = 0, firstZero = -1;
        
        while(index < nums.size()) {
            if(nums[index] == 0 && firstZero == -1) {
                firstZero = index;
            } else if(nums[index] != 0 && firstZero != -1) {
                swap(nums[index], nums[firstZero]);
                findFirstZero(nums, ++firstZero);
            }
            ++index;
        }
        
    }
};