class Solution {
  public:
    int countBitsFlip(int a, int b) {
        int n=a^b;
        int count=0;
        while(n>0){
            if (n&1==1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
};
