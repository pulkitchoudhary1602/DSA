class Solution {
public:
    int findKthNumber(int n, int m, int k) {  //n->no of rows, m->no of cols
        int low=0;
        int high=n*m;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(countless(n,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    bool countless(int n, int m, int k,int guess){
        int count=0;
        for(int i=1;i<=n;i++){
            count=count+min(m,guess/i);
        }
        if(count<k) return false;
        else return true;
    }
};