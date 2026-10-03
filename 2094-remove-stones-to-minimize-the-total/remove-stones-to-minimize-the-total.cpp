class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans=0;
        int n=piles.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
            ans+=piles[i];
        }
        for(int i=0;i<k;i++){
            int maxi=pq.top();
            pq.pop();
            ans-=(maxi)/2;
            pq.push((maxi+1)/2);
        }
        return ans;
    }
};