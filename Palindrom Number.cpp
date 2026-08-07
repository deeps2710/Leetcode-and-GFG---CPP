class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x;
        long long rev=0;
        int digit;
        while(x>0){
            digit=x%10;
            rev=rev*10+digit;
            x=x/10;
        }
        return temp==rev;
    }
};
