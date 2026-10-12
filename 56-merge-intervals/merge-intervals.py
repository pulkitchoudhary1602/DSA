class Solution:
    def merge(self, arr: list[list[int]]) -> list[list[int]]:
        ans=[]
        n=len(arr)
        arr.sort()
        if(n==0):
            return ans
        start1=arr[0][0]
        end1=arr[0][1]
        for i in range(1,n):
            start2=arr[i][0]
            end2=arr[i][1]
            if(end1>=start2):
                end1=max(end1,end2)
            else:
                ans.append([start1,end1])
                start1=start2
                end1=end2
        ans.append([start1,end1])
        return ans