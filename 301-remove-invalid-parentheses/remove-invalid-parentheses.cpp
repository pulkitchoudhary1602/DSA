class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string>q;
        unordered_set<string>vis;
        vector<string>ans;
        q.push(s);
        while(!q.empty()){
            int n=q.size();
            bool found=false;
            while(n--){
                string curr=q.front();
                q.pop();
                if(valid(curr)){
                    ans.push_back(curr);
                    found=true;
                }
                if(found) continue;
                for(int i=0;i<curr.size();i++){
                    if(curr[i]!='(' && curr[i]!=')'){
                        continue;
                    }
                    string next=curr.substr(0,i)+curr.substr(i+1);
                    if(vis.count(next)==0){
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            if(found) break;
        }
        return ans;
    }
    bool valid(string s){
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                cnt--;
                if(cnt<0) return false;
            }
        }
        return cnt==0;
    }
};