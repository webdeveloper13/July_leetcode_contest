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

//pro solution using xor ... O(n) time O(1) space
/*
Explanation:
Input:  [1,2,1,3,2,5]
Consider this above input
First take xor of whole array and store it in xor_op.
So after doing this you will actually have 3^5 stored in xor_op because rest all will be zero.
So now we find the lowest set bit for this. 
now we have two groups(one which have 1 as set bit in lowest and one which have 0) in the vector.One which have 
and after dividing them in two separate groups we use xor so that finally will have the single numbers in each group
and we return it
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
    vector<int> singleNumber(vector<int>& nums) {
            int xor_op = 0;
            for(auto x:nums)
            {
                    xor_op ^= x;
            }
            
            int lowest_set_bit = xor_op&(-xor_op);
            vector<int> ans(2,0);
            for(auto x:nums)
            {
                    if((x & lowest_set_bit)==0)
                            ans[0] ^= x;
                    else
                            ans[1] ^= x;
            }
            
            return ans;
        
    }
};





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