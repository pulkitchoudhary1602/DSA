class Solution {
public:
    int minimumPushes(string word) {
        int s=word.size();
        if(s<8) return s;
        int i=1;
        int ans=0;
        while(s>0){
            if(s>8){
                ans=ans+i*(8);
            }
            else{
                ans=ans+i*(s);
            }
            s=s-8;
            i++;
        }
        return ans;
    }
};