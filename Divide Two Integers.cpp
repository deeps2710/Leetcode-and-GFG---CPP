class Solution {
public:
    int divide(int dividend, int divisor) {
        long long count=0;
        bool sign=false;

        //Overflow case
        if (dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        
        if (dividend>0 && divisor<0 || dividend<0 && divisor>0){
            sign=true;
        }
        long long dvd=abs((long long)dividend);
        long long div=abs((long long)divisor);

        while(dvd>=div){
            int power=0;

            //largest div*2^power that fits in dvd
            while(dvd>=(div<<(power+1))){
                power++;
            }
            dvd-=div<<power;
            count+=1LL<<power;
        }
        
        if (sign==true){
            return -count;
        }else{
            return count;
        }
    }
};
