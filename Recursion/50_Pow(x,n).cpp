class Solution {
public:
    
    
    double getPow(double x, int n) {
        
        if(n == 0) {
            return 1;
        }
        
        double smallRes = getPow(x,floor(n / 2));
        smallRes *= smallRes;
        
        if(n % 2 != 0) {
            smallRes *= x;
        }
        
        return smallRes;
        
    }
    
    double myPow(double x, int n) {
        
        if(n == 0 || x == 1) {
            return 1;
        }
        
        long int absN = (n > 0) ? n : (long int)(n) * -1;
        
        double res = getPow(x, absN);
        
        if(n < 0) {
            return 1 / res;
        }
        
        return res;
    }
};
