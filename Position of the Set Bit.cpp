class Solution {
  public:
    int findPosition(int n) {
        int count=0;
        int pos=0;
        while(n>0){
            pos++;
            if(n&1!=0){
                count++;
            }
            n=n>>1;
        }
    if (count==1){
        return pos;
    }
    return -1;
    }
};
