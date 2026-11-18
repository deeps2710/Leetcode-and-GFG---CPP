class Solution {
  public:
    void del(stack<int>& s, int c, int p){
        if(s.empty()){
            return;
        }
        if(c==p){ //base condition
            s.pop();
            return;
        }
        int x=s.top();
        s.pop();
        del(s, c+1, p);
        s.push(x);
        return;
    }
    void deleteMid(stack<int>& s) {
        float sz=s.size();
        int pos=ceil((sz+1)/2);
        int count=1;
        del(s, count, pos);
    }
};
