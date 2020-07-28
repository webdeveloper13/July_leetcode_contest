/*
Task Scheduler

Solution
You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> id
*/

/*Approach
if n is zero return the number of tasks
else find the most frequent task.
idle time will be (mostfrequent-1)*n;
then fill the other tasks now by decrementing the idle time by their frequencies
if idle time falls below 0 return number of tasks;
else return idle time + number of tasks.

Time Complexity: O(n +26log26)
Space: O(1);
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
    int leastInterval(vector<char>& tasks, int x) {
            int n = tasks.size();
            if(x==0)
                    return n;
            vector<int> freq(26,0);
            for(auto it:tasks)
            {
                    freq[it-'A']++;
            }
            
            sort(freq.begin(),freq.end());
            int mostFreq = freq[25]-1;
            int idleTime = mostFreq*x;
            for(int i=24;i>=0;i--)
            {
                    idleTime -= min(mostFreq,freq[i]);
                    if(idleTime<0)
                            return n;
            }
            
            return idleTime+n;
            
    }
};



/*
["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2

A->B->C->A->D->E->A->F->G->A->i->i->A->i->i->A

["A","A","A","B","B","B"], n = 2

A->B->i->A->i->i->A->i-> 
B B B

        
*/        