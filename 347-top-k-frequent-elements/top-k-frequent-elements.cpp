class Solution {
public:
    struct cmp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            if (a.first != b.first)
                return a.first > b.first;      // Min heap by frequency
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for (auto it : freq) {
            int element = it.first;
            int f = it.second;

            if (pq.size() < k) {
                pq.push({f, element});      // {frequency, element}
            } else if (f > pq.top().first) {
                pq.pop();
                pq.push({f, element});
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};