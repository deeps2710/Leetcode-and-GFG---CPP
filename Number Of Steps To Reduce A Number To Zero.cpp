class Solution {
public:
    int numberOfSteps(int num) {
        int steps=0;
        while(num>0){
            if(num&1){  //if last bit is 1, it's odd
                num^=1; //num--
            }else{  //if last bit is 0, even
                num>>=1; // num/2
            }
            steps++;
        }
        return steps;
    }
};
