/*
Add Binary

Solution
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/

/*
Basically start from right for both the strings and store digits in x and y (which are initially zero)
then add  x,y and carry and take mod 2 (because sum will range from 0 to 3 so if sum is 3 mod will be 1 and so on)
after doing this append it to result string
now to calculate carry divide sum by 2
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
    string addBinary(string a, string b) {
            int carry = 0;
            string ans="";
            int m = a.length();
            int n = b.length();
            int i = 0;
            while(i<m || i<n || carry!=0)
            {
                    int x = 0;
                    if(i<m && a[m-1-i]=='1')
                            x = 1;
                    int y=0;
                    if(i<n && b[n-1-i]=='1')
                            y=1;
                    ans = (char)((x+y+carry)%2+'0') +ans;
                    carry = (x+y+carry)/2;
                    i++;
                            
             }
            
            return ans;
    }
};

/*
a = "1010", b = "1011"
        
1010
1011
1 0 1 0 1    

11
 1
1 0 0      

*/