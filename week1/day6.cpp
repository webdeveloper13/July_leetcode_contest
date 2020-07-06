/*
Plus One

Solution
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
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
    vector<int> plusOne(vector<int>& digits) {
            int carry = 1;
            for(int i=digits.size()-1;i>=0 && carry!=0;i--)
            {
                    int sum = digits[i]+carry;
                    carry = sum/10;
                    sum = sum%10;
                    digits[i] = sum;
            }
            
            if(carry)
            {
                    digits[0] = 1;
                    digits.emplace_back(0);
            }
            
            return digits;
    }
};