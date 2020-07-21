/*
Word Search

Solution
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

/*
Approach : DFS+backtracking
*/
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
    bool dfs(vector<vector<char>>& board,int i,int j,string word,int count)
    {
            if(count==word.length())
                    return true;
            if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[count])
                    return false;
            char temp = board[i][j];
            board[i][j] = '$';
            bool ans= (dfs(board,i+1,j,word,count+1)||dfs(board,i-1,j,word,count+1)
                   ||dfs(board,i,j+1,word,count+1)||dfs(board,i,j-1,word,count+1));
            board[i][j] = temp;
            return ans;
            
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
            for(int i=0;i<board.size();i++)
            {
                    for(int j=0;j<board[0].size();j++)
                    {
                            if(board[i][j]==word[0] && dfs(board,i,j,word,0))
                                    return true;
                    }
            }
            
            return false;
        
    }
};