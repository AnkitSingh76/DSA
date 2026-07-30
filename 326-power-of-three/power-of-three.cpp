class Solution {
public:
    bool isPowerOfThree(int n) {
         if(n<=0)
        return 0;

        while(n>=2){
            if(n%3==1||n%3==2)
            return 0;

            n=n/3;
        }
        return 1;
    }
};