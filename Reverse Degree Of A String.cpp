class Solution {
public:
    int reverseDegree(string s) {
        int i=1;
        int sum=0;
        int product;
        for(char ch: s){
            product=('z'-ch+1)*i;
            sum+=product;
            i++;
        }
        return sum;
    }
};
