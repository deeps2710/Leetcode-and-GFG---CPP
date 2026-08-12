METHOD 1:
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int answer1=0;
        int answer2=0;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    answer1++;
                    break;
                }
            }
        }
        for(int i=0; i<nums2.size(); i++){
            for(int j=0; j<nums1.size(); j++){
                if(nums2[i]==nums1[j]){
                    answer2++;
                    break;
                }
            }
        }
        return {answer1, answer2};
    }
};


METHOD 2:
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int answer1=0;
        int answer2=0;
        unordered_map<int, int> num1;
        unordered_map<int, int> num2;
        for(int i: nums1){
            num1[i]+=1;
        }
        for(int j: nums2){
            num2[j]+=1;  
        }
        for(int i: nums1){
            if(num2[i]>0){
                answer1++;
            }
        }
        for(int i: nums2){
            if(num1[i]>0){
                answer2++;
            }
        }
        return {answer1, answer2};
    }
};
