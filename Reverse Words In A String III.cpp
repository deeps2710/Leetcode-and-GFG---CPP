class Solution {
public:
    string reverseWords(string s) {
        int str=0;
        for(int i=0; i<=s.size(); i++){
            if(i==s.size() || s[i]==' '){
                int left=str;
                int right=i-1;
                while(left<right){
                    char temp=s[left];
                    s[left]=s[right];
                    s[right]=temp;
                    left++;
                    right--;
                }
                str=i+1;
            }
        }
        
        return s;
    }
};
