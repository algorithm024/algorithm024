class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
       
        n=len(nums)
        nums[:]=nums[n-k:]+nums[0:n-k]
        print nums
