class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,string>& a,
                        const pair<int,string>& b) const {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> mp;

        for (string &word : words)
            mp[word]++;

        priority_queue<pair<int,string>,
                       vector<pair<int,string>>,
                       cmp> pq;

        for (auto &it : mp) {
            if (pq.size() < k) {
                pq.push({it.second, it.first});
            }
            else if (it.second > pq.top().first ||
                    (it.second == pq.top().first &&
                     it.first < pq.top().second)) {
                pq.pop();
                pq.push({it.second, it.first});
            }
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};