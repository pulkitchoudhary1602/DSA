class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int v=0;
        int x=0;
        int xx=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                v++;
            }
            else if(bills[i]==10){
                if(v<1) return false;
                v--;
                x++;
            }
            else{
                if(x>=1 && v>=1){
                    x--;
                    v--;
                    xx++;
                }
                else if(v>=3){
                    v-=3;
                    xx++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};