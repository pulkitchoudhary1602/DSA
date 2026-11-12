class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if(cost1+cost2<=costBoth){
            return 1ll*need1*cost1+1ll*need2*cost2;
        }
        else{
            int both=min(need1,need2);
            ans=1ll*both*costBoth;
            need1-=both;
            need2-=both;
            if(need1>0){
                ans+=1ll*need1*min(costBoth,cost1);
            }
            else if(need2>0){
                ans+=1ll*need2*min(costBoth,cost2);
            }
        }
        return ans;
    }
};