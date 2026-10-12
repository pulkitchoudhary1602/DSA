class Solution:
    def insert(self, arr: list[list[int]], new: list[int]) -> list[list[int]]:
        insert=False
        arr.sort()
        res=[]
        n=len(arr)
        for i in range(n):
            if(insert==False and arr[i][0]>new[0]):
                res.append(new)
                insert=True
            res.append(arr[i])
        if(insert==False):
            res.append(new)
        start1=res[0][0]
        end1=res[0][1]
        ans=[]
        n=len(res)
        for i in range(1,n):
            start2=res[i][0]
            end2=res[i][1]
            if(end1>=start2):
                end1=max(end1,end2)
            else:
                ans.append([start1,end1])
                start1=start2
                end1=end2
        ans.append([start1,end1])
        return ans