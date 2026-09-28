class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        //row offset (-n+1,n-1)
        //col offset (-n+1,n-1)
        int n=img1.size();
        int maxi=0;
        for(int rowoff=-n+1;rowoff<n;rowoff++){
            for(int coloff=-n+1;coloff<n;coloff++){
                int count=overlaps(img1,img2,rowoff,coloff,n);
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
    int overlaps(vector<vector<int>>& img1, vector<vector<int>>& img2,int rowoff,int coloff,int n){
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int row=i+rowoff;
                int col=j+coloff;
                if(row>=0 && row<n && col>=0 && col<n){
                    if(img1[i][j]==1 && img2[row][col]==1){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};