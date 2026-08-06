class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            if(proddigi(n)%t==0) return n;
            else n++;
        }
    }
    int proddigi(int num){
        int ans=1;
        while(num>0){
            ans=ans*(num%10);
            num=num/10;
        }
        return ans;
    }
};