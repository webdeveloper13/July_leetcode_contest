/*
Single Number III

Solution
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/


//NOOB solution
//takes O(n) space and O(n) time
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans;
            unordered_map<int,int> um1;
            for(auto x:nums)
                    um1[x]++;
            for(auto it = um1.begin();it!=um1.end();it++)
            {
                    if(um1[it->first]==1)
                            ans.push_back(it->first);
            }
            
            return ans;

        
    }
};


/* -1 0
Input:  [1,2,1,3,2,5]
Output: [3,5]

1 2 1 -3 2 -5 
*/