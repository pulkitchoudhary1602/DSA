// class Solution {
// public:
//     bool uniformArray(vector<int>& nums1) {
//         int miniodd=INT_MAX;
//         int minieven=INT_MAX;
//         int cntodd=0;
//         int cnteven=0;
//         int n=nums1.size();
//         for(int i=0;i<n;i++){
//             if(nums1[i]%2==0){
//                 cnteven++;
//                 minieven=min(nums1[i],minieven);
//             }
//             else{
//                 cntodd++;
//                 miniodd=min(nums1[i],miniodd);
//             }
//         }
//         if(cnteven==n || cntodd==n) return true;
//         else {
//             if(minieven-miniodd>=1) return true;
//             else return false;
//         }
//     }
// };
class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int x : nums) {
            if (x % 2 == 0)
                minEven = min(minEven, x);
            else
                minOdd = min(minOdd, x);
        }

        if (minOdd == INT_MAX || minEven == INT_MAX)
            return true;

        return minEven > minOdd;
    }
};