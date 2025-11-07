class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false ;
      long int  n= x;
     long  int  re= 0;
        while (x>0){
            int r= x%10;
            re =( re*10)+r;
x/=10;
        }
        if (n==re) return true ;
        return false ;
    }
};