/*
Add Digits

Solution
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/

//Solution 1: using digital root formula from wiki --answer = n - 9 * floor((n-1) / 9)
class Solution {
public:
    int addDigits(int num) {
        return num - (num - 1) / 9 * 9;
    }
};



//Solution 2:Naive approach using loop
class Solution {
public:
    int addDigits(int num) {
        int temp = 0;
        while(num>=10)
        {
                while(num>0)
                {
                     temp += num%10;
                     num = num/10;   
                        
                }
                
                num = temp;
                temp = 0;
        }
            
        if(num<0)
                return 0;
        return num;    
    }
};



