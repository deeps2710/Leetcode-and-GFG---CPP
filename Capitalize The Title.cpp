class Solution {
public:
    string capitalizeTitle(string title) {
        int n=title.size();
        int i=0;
        while(i<n){
            int start=i;
            while(i<n && title[i]!=' '){
                title[i]=tolower(title[i]);
                i++;
            }
            int wordlen=i-start;
            if(wordlen>2){
                title[start]=toupper(title[start]);
            }
            i++;
        }
        return title;
    }
};
