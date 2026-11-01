class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num1/100==0 && num2/100==0) return 0;
        int ans=0;
        for(int i=num1;i<=num2;i++){
            ans+=fun(i);
        }
        return ans;
    }
    int fun(int n){
        string s=to_string(n);
        int cnt=0;
        for(int i=1;i<s.size()-1;i++){
            if((s[i-1]>s[i] && s[i]<s[i+1])||(s[i]>s[i-1] && s[i]>s[i+1])){
                cnt++;
            }
        }
        return cnt;
    }
};