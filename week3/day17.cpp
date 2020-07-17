/*
Top K Frequent Elements

Solution
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/
/*
Approach:
Using priority queue and unordered hash map.
unordered hash map takes O(1) time for operations
so we store frequencies there in o(1) time there

and then we use priority queue of dt pair as it stores value in descending order
insert takes O(logn) time and then we pop first k elements from pq;s
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> ans;
            if(n==1)
            {
                    ans.push_back(nums[0]);
                    return ans;
            }
            unordered_map<int,int> um1;
            for(auto i:nums)
            {
                   um1[i]++;
            }
            
            priority_queue<pair<int,int>> pq1;
            for(auto it:um1)
            {
                    pq1.push({it.second,it.first});
            }
            
            for(int i=1;i<=k;i++)
            {
                    ans.push_back(pq1.top().second);
                    pq1.pop();
            }
            
            return ans;
            }
};