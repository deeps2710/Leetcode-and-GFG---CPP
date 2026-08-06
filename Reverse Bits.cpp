class Solution {
public:
    int reverseBits(int n) {
        long long num=0;
        for(int shift=0; shift<32; shift++){
            if((n&(1LL<<shift))!=0){
                num=num|(1LL<<abs(31-shift));
            }
        }
        return static_cast<int>(num);
    }
};
