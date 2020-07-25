/*
Find Minimum in Rotated Sorted Array II

Solution
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/

/*Approach
So basically we solve it by using binary search here.
left = 0 right = n-1
so while left is less than right
we find mid
Now we check if mid is greater than right
if it is
then we set left to mid+1 because if normally array is sorted the mid would be 
less than right but here since mid element is greater than right element
we conclude that mid is not minimum and hence we search on right side now.

else if mid is less than right
we shift right to mid

if mid is equal to right (because of duplicates)
we simply exclude that right element by decrementing it.(right--)
*/


auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
public:
    int findMin(vector<int>& nums) {
            int n = nums.size();
            int left = 0;
            int right = n-1;
            while(left<right)
            {
                    int mid = left + (right-left)/2;
                    if(nums[mid]>nums[right])
                    {
                            left = mid+1;
                    }
                    
                    else if(nums[mid]<nums[right])
                    {
                            right = mid;
                    }
                    
                    else
                    {
                            right--;
                    }
            }
            
            return nums[left];
        
    }
};