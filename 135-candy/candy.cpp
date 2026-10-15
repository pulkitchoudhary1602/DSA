class Solution {
public:
    int candy(vector<int>& arr) {
        int sum=1;
        int i=1;
        int n=arr.size();
        while(i<n){
            if(arr[i]==arr[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && arr[i]>arr[i-1]){ // upward peak
                peak+=1;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && arr[i]<arr[i-1]){ //downward peak
                sum+=down;
                down+=1;
                i++;
            }
            if(down>peak){
                sum+=down-peak;
            }
        }
        return sum;
    }
};