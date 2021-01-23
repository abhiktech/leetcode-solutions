class Solution {
    
public:
    
    int fact(int n) {
        int f = 1;
        while(n > 1) {
            f *= n;
            --n;
        }
        return f;
    }
    
    string getPermutation(int n, int k) {
        
        if(n == 1) {
            return "1";
        }
        
        --k;
        
        string res = "";
        
        string unused = "";
        
        for(int i = 1; i <= n; ++i) {
            unused += to_string(i);
        }
        
        int factorial = fact(n - 1);
        
        for(int i = n - 1; i >= 1; --i) {
            int index = k / factorial;
            k = k % factorial;
            factorial /= i;
            res += unused[index];
            unused = unused.substr(0, index) + unused.substr(index + 1);   
        }
        
        res += unused;
        
        return res;
    }
};