class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n=text.size();
        long long first=0;
        long long second=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(text[i]==pattern[1]){
                ans+=first;
                second++;
            }
            if(text[i]==pattern[0]){
                first++;
            }
        }
        return ans+max(first,second);
    }
};