class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k==0) return num;
        if(k==n) return "0";
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()-'0'>num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();
        }
        if(res.empty()) return "0";
        reverse(res.begin(),res.end());
        return res;
    }
};