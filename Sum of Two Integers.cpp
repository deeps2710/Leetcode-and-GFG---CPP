class Solution {
public:
    int getSum(int a, int b) {
        int sum=a^b;
        int carry=a&b;
        int new_carry=carry<<1;
        while(new_carry!=0){
            carry=sum&new_carry;
            sum=sum^new_carry;
            new_carry=carry<<1;
        }
        return sum;
    }
};
