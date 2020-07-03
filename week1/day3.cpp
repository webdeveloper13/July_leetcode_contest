/*
Prison Cells After N Days

Solution
There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

 

Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]
 
*/

//Solution 1: After some steps the pattern will repeat

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        set<vector<int>> mp;
        while (N > 0) {
            vector<int> temp = cells;
            for (int i = 1; i < temp.size() - 1; i++) {
                if (cells[i-1] == 0 && cells[i+1] == 0) {
                    temp[i] = 1;
                } else if (cells[i-1] == 1 && cells[i+1] == 1) {
                    temp[i] = 1;
                } else {
                    temp[i] = 0;
                }
            }            
            temp[0] = 0; 
            temp[temp.size() -1] = 0;
            cells = temp;
            auto it = mp.find(cells);
            if (it != mp.end()) {
                N--;
                N = N%mp.size();
            } else {
                N--;
                mp.insert(cells);
            }
        }   
        return cells;    
    }
};





//Solution 2: 
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        N = N%14==0 ? 14 : N%14;
        vector<int> cells2(8,0); 
        while(N>0)
        {
            for(int i=1;i<cells.size()-1;i++)
            {
                cells2[i] = cells[i-1] == cells[i+1] ? 1 : 0;
            }
            cells = cells2;
            N--;
        }
        
        return cells;
    }
};