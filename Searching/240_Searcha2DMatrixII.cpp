class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int col = 0;
        
        for(int row = static_cast<int>(matrix.size()) - 1; row >= 0; --row) {
            
            int newCol = col;
            
            while(newCol < matrix[row].size() && matrix[row][newCol] < target) {
                ++newCol;
            }
            
            if(newCol == matrix[row].size()) {
                return false;
            } else if(matrix[row][newCol] == target) {
                return true;
            } else {
                col = newCol;
            }
            
        }
        
        return false;
    }
};