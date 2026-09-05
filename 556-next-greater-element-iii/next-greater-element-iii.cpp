class Solution {
public:
    int nextGreaterElement(int num) {
       string s=to_string(num);
       int n=s.size();
       int index=-1;
       for(int i=n-2;i>=0;i--){
        if(s[i]<s[i+1]){
            index=i;
            break;
        }
       }
       if(index==-1){
        return -1;
       } 
       else{
        for(int i=n-1;i>=index;i--){
            if(s[i]>s[index]){
                swap(s[i],s[index]);
                break;
            }
        }
        reverse(s.begin()+index+1,s.end());
        long long ans = stoll(s);
        if(ans>INT_MAX) return -1;
        else return ans;
       }
    }
};