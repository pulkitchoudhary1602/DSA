class Solution {
public:
    int minGroups(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        priority_queue<int,vector<int>,greater<int>>pq; //min-heap;
        for(auto it:arr){
            int start=it[0];
            int end=it[1];
            if(!pq.empty() && start>pq.top()){
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
    }
};