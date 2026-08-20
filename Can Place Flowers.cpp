class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0; i<flowerbed.size(); i++){
            //either i is 0th index or left of i is 0
            //AND
            //either i is last element or right of i is 0
            if(flowerbed[i]==0 &&
            (i==0 || flowerbed[i-1]==0)&&
            (i==flowerbed.size()-1 || flowerbed[i+1]==0)){
                flowerbed[i]=1;
                n--;
            }
        }
        return n<=0;
    }
};
