/*
 Word Break II

Solution
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/
class Solution {
    vector<string> wordUtil(string s,int start,unordered_map<int,vector<string>> um1,unordered_set<string> us1)
    {
           if(um1.find(start)!=um1.end())
           {
                   return um1[start];
           }

            vector<string> ans;
            if(start==s.length())
                    ans.push_back("");
            for(int end = start+1;end<s.length();end++)
            {
                    string prefix = s.substr(start,(end-start+1));
                    if(us1.find(prefix)!=us1.end())
                    {
                            vector<string> suffixes = wordUtil(s,end,um1,us1);
                            for(auto suffix:suffixes)
                            {
                                    string temp = prefix +((suffix=="")?"":" ")+suffix;
                                    ans.push_back(temp);
                            }
                    }
            }
            um1[start] = ans;
            return ans;
                   
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
            unordered_map<int,vector<string>> um1;
            unordered_set<string> us1;
            for(auto k:wordDict)
                    us1.insert(k);
            return wordUtil(s,0,um1,us1);
        
    }
};