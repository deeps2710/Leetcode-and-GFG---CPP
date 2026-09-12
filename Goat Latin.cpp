class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans="";
        string word="";
        sentence+=" ";
        int count=1;
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i]!=' '){
                word+=sentence[i];
            }else{
                char ch=word[0];
                bool vowel=ch=='a'||ch=='e'||
                    ch=='i'||ch=='o'||ch=='u'||
                    ch=='A'||ch=='E'||ch=='I'||
                    ch=='O'||ch=='U';
                
                if(!vowel){
                    char first=word[0];
                    for(int j=1; j<word.size(); j++){
                        word[j-1]=word[j];
                    }
                    word[word.size()-1]=first;
                }
                word+="ma";
                word+=string(count,'a');
                if(ans!=""){
                    ans+=" ";
                }
                ans+=word;
                word="";
                count++;
            }
        }
        return ans;
    }
};
