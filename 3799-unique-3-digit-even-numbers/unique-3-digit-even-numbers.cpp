class Solution {
public:
    int totalNumbers(vector<int>& arr) {
        vector<int>freq(10,0);
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        for(int e:{0,2,4,6,8}){
            if(freq[e]==0) continue;
            freq[e]--;
            for(int h=1;h<=9;h++){
                if(freq[h]==0) continue;
                freq[h]--;
                for(int j=0;j<=9;j++){
                    if(freq[j]>0) ans++;
                }
                freq[h]++;
            }
            freq[e]++;
        }
        return ans;
    }
};