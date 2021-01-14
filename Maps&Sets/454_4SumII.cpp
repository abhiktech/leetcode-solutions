class Solution {
public:
    
    void calculateSumOfPairs(vector<int>& A, vector<int>& B, unordered_map<int, int>& cur) {
        for(size_t i = 0; i < A.size(); ++i) {
            for(size_t j = 0; j < B.size(); ++j) {
                ++cur[A[i] + B[j]];
            }
        }
    }
    
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        unordered_map<int, int> f;
        unordered_map<int, int> s;
        
        calculateSumOfPairs(A, B, f);
        calculateSumOfPairs(C, D, s);
        
        int num = 0;
        
        for(auto& i : f) {
            num += i.second * s[-1 * i.first];
        }
        
        return num;
    }
};