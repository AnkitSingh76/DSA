class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return 0;

         int num=x,ans=0,rem;
         while(x)
         {
            rem=x%10;
            x=x/10;
            if(ans>INT_MAX/10)
            return 0;
            ans=ans*10+rem;
         }

          if(ans==num)
          return 1;
          else
          return 0;
    }
};