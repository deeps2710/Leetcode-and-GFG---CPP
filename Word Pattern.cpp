class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //extact words into a string vector
        vector<string> temp;
        string word="";
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                if(!word.empty()){
                    temp.push_back(word);
                    word="";
                }
            }else{
                word+=s[i];
            }
        }
        if(!word.empty()){
            temp.push_back(word);
        }

        if(pattern.size()!=temp.size()){
            return false;
        }

        //check for isomorphic strings now
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        for(int i=0; i<pattern.size(); i++){
            char a=pattern[i];
            string b=temp[i];

            if(mp1.find(a)!=mp1.end()){
                if(mp1[a]!=b){
                    return false;
                }
            }else{
                mp1[a]=b;
            }

            if(mp2.find(b)!=mp2.end()){
                if(mp2[b]!=a){
                    return false;
                }
            }else{
                mp2[b]=a;
            }
        }
        return true;
    }
};
