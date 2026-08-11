class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=0;
        int maxp=0;
        for(int i=0; i<prices.size(); i++){
            if (prices[i]<prices[mini]){
                mini=i;
            }
            if (prices[i]-prices[mini]>maxp){
                maxp=prices[i]-prices[mini];
            }
        }
        return maxp;
    }
};
