class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        while(num){
            int curr=min(9,sum);
            sum-=curr;
            ans+=to_string(curr);
            num--;
        }
        if(sum>0) return "";
        return ans;
    }
};