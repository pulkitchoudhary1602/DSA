class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1||numRows==n) return s;
        vector<string>arr(numRows);
        int row=0;
        int dir=1;
        for(int i=0;i<n;i++){
            char ch=s[i];
            arr[row]+=ch;
            if(row==0) dir=1;
            if(row==numRows-1) dir=-1;
            row+=dir;
        }
        string ans;
        for(auto it:arr){
            ans+=it;
        }
        return ans;
    }
};