class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        //initially take k cards from left
        for(int i=0; i<k; i++){
            sum+=cardPoints[i];
        }
        int maxsum=sum;
        //replace left cards with right cards
        for(int i=1; i<=k; i++){
            sum-=cardPoints[k-i];
            sum+=cardPoints[n-i];
            maxsum=max(maxsum, sum);
        }
        return maxsum;
    }
};
