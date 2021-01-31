class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        p=0
        q=1
        while q<len(nums):
            if nums[p]!=nums[q]:
                if p+1!=q:
                    nums[p+1]=nums[q]
                p+=1
            q+=1
        return p+1
