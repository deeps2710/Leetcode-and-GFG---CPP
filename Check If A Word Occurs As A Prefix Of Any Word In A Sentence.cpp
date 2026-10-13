class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size();
        int m=searchWord.size();
        int i=0, word=1;

        while(i<n){
            int j=0;
            while(i+j<n && j<m && sentence[i+j]==searchWord[j]){
                j++;
            }
            if(j==m){
                return word;
            }
            while(i<n && sentence[i]!=' '){
                i++;
            }
            i++;
            word++;
        }
        return -1;
    }
};
