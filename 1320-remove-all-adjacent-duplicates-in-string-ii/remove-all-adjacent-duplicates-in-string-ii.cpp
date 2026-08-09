class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans="";
        stack<pair<char,int>>st;
        for(auto ch:s){
            if(st.empty()){
                st.push({ch,1});
                continue;
            }
            if(ch!=st.top().first){
                st.push({ch,1});
                continue;
            }
            if(st.top().second<k-1){
                pair<char,int> temp=st.top();
                st.pop();
                st.push({temp.first,temp.second+1});
                continue;
            }
            st.pop();
        }
        while(st.empty()==false){
            pair<char,int>temp=st.top();
            st.pop();
            while(temp.second--){
                ans.push_back(temp.first);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};