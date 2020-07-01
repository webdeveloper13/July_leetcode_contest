/*Arranging Coins

Solution
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
*/

//Solution 1:Brute force
//TC: O(n)
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
public:
    int arrangeCoins(int n) {
            if(n==0)
                    return 0;
            int count = 0;
            int i = 1;
            while(n>0)
            {
                    if(n-i>=0)
                            count++;
                   
                    n=n-i;
                    i++;
            }
            
            return count;
            
        
    }
};


//Solution 2:using formula
//TC: O(1)
class Solution {
public:
    int arrangeCoins(int n) {
           return (sqrt(8*(long long)n+1)-1)/2;

    }
};


//Solution 3:Binary search
//TC: O(logn)
class Solution {
public:
      int arrangeCoins(int n) {
        long low = 1, high = n;
        while (low < high) {
            long mid = low + (high - low + 1) / 2;
            if ((mid + 1) * mid / 2.0 <= n) low = mid;
            else high = mid - 1;
        }
        return high;
    }
};