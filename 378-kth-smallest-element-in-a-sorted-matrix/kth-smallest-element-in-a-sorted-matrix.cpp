class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=matrix[0][0];
        int high=matrix[n-1][m-1];
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(countless(matrix,k,mid,n,m)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    bool countless(vector<vector<int>>& matrix, int k,int guess,int n,int m){
        int count=0;
        int row=m-1;
        int col=0;
        while(row>=0 && col<m){
            if(matrix[row][col]>guess){
                row--;
            }
            else{
                col++;
                count=count+row+1;
            }
        }
        if(count<k) return false;
        else return true;
    }
};