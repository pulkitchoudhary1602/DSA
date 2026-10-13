class Solution {
public:
    int minNumberOfFrogs(string s) {
        int n=s.size();
        if(s[0]!='c' || n<5) return -1;
        int active=0;
        int ans=0;
        vector<int>cnt(5,0);
        for(int i=0;i<n;i++){
            if(s[i]=='c'){
                active++;
                cnt[0]++;
                ans=max(ans,active);
            }
            else if(s[i]=='r'){
                if(cnt[0]==0) return -1;
                cnt[0]--;
                cnt[1]++;
            }
            else if(s[i]=='o'){
                if(cnt[1]==0) return -1;
                cnt[1]--;
                cnt[2]++;
            }
            else if(s[i]=='a'){
                if(cnt[2]==0) return -1;
                cnt[2]--;
                cnt[3]++;
            }
            else{
                if(cnt[3]==0) return -1;
                active--;
                cnt[3]--;
            }
        }
        if(active!=0) return -1;
        else return ans;
    }
};