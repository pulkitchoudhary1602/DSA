class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>avl; //store id
        for(int i=0;i<k;i++){
            avl.insert(i);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;  //{finish_time,id}
        vector<int> cnt(k,0);
        int n=arrival.size();
        for(int i=0;i<n;i++){
            int time=arrival[i];
            while(!pq.empty() && pq.top().first<=time){
                int id=pq.top().second;
                pq.pop();
                avl.insert(id);
            }
            int target=i%k;
            auto it=avl.lower_bound(target);
            if(it==avl.end()){
                it=avl.begin();
            }
            if(avl.empty()){
                continue;
            }
            int id=*it;
            avl.erase(it);
            pq.push({time+load[i],id});
            cnt[id]++;
        }
        int maxi=0;
        for(int i=0;i<k;i++){
            maxi=max(cnt[i],maxi);
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            if(cnt[i]==maxi){
                ans.push_back(i);
            }
        }
        return ans;
    }
};