class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
      vector<vector<int>>ans;
      sort(arr.begin(),arr.end());
      int start1=arr[0][0];
      int end1=arr[0][1];
      int n=arr.size();
      for(int i=1;i<n;i++){
        int start2=arr[i][0];
        int end2=arr[i][1];
        if(end1>=start2){
            end1=max(end1,end2);
            continue;
        }
        ans.push_back({start1,end1});
        start1=start2;
        end1=end2;
      }
      ans.push_back({start1,end1});
      return ans;
    }
};