class Solution {
public:
    bool checkString(string s) {
        bool start=false;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='b' && start==false){
                start=true;
            }
            if(s[i]=='a' && start==true){
                return false;
            }
        }
        return true;
    }
};