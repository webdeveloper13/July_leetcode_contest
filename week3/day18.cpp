/*
Course Schedule II
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

//Solution 1: TopoSorting using kahns algo
/*Approach
So here we use topological sort for a DAG to solve this problem
To be precise this is Kahn's Algorithm where we have an indegree array
which computes number of incoming edge towards a node.
In this case a value will have an incoming edge only if it has some prerequisite
So we first find a course with zero prereq(zero indegree) we first do that course
and we decrease the indegree by 1 for those subjects which were dependent on this course.
Likewise we keep repeating this.

In the end we see if have covered all the nodes that is if we have the size of array
same ans numCourses if yes we return otherwise we return empty array
*/

auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        int n = prereq.size();
        vector<int> ans;
        if(numCourses==1)
        {
                ans.push_back(0);
                return ans;
        }    
      
                
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<n;i++)
        {
                adj[prereq[i][1]].push_back(prereq[i][0]);
        }
            
        
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
                for(int j=0;j<adj[i].size();j++)
                {
                        indegree[adj[i][j]]++;
                }
        }
            
        queue<int> q;    
            
        for(int i=0;i<numCourses;i++)
        {
                if(indegree[i]==0)
                        q.push(i);
                        
        }
            
      /*  for(auto it:indegree)
                cout<<it<<" ";*/
            
        
        while(!q.empty())
        {
                int curr = q.front();
                ans.push_back(curr);
                q.pop();
                
                for(int i=0;i<adj[curr].size();i++)
                {
                        if(--indegree[adj[curr][i]]==0)
                                q.push(adj[curr][i]);
                }
        }
            
        if(ans.size()!=numCourses)
        {
                ans.clear();
                return ans;
        }
            
        return ans;    
            
    }
};


//Solution 2: TopoSorting using DFS+STACK

/*
Approach: Start dfs traversal from a node which is not yet visited and once a node does not have 
an outgoing edge ,push it to stack and then backtrack.
Finally pop from stack and you will get topological sorted order.
*/
/*
Also as we know Topo Sorting only work for a DAG so before starting,we check if
there is a cycle and cycle detection in an undirected graph can be done by Graph
Colouring method
*/

class Solution {
    /*Graph coloring: 0->not visited.
    1->visited...
    2->visited & processed
    */
    bool detectCycle_util(vector<vector<int>>& adj,vector<int>& visited,int v)
    {
        if(visited[v]==1)
            return true;
        if(visited[v]==2)
            return false;
        
        visited[v]=1;   
        for(int i=0;i<adj[v].size();++i)
            if(detectCycle_util(adj,visited,adj[v][i]))
                return true;
        
        visited[v]=2;   
        return false;
    }
    
    bool detectCycle(vector<vector<int>>& adj,int n)
    {
        vector<int> visited(n,0);
        for(int i=0;i<n;++i)
            if(!visited[i])
                if(detectCycle_util(adj,visited,i))
                    return true;
        return false;
    }
    
    void dfs(vector<vector<int>>& adj,int v,vector<bool>& visited,stack<int>& mystack)
    {
        visited[v] = true;
        for(int i=0;i<adj[v].size();++i)
            if(!visited[adj[v][i]])
                dfs(adj,adj[v][i],visited,mystack);
        
        mystack.push(v);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<n;++i)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<int> ans;
        if(detectCycle(adj,numCourses))
            return ans;        
        
        stack<int> mystack;
        vector<bool> visited(numCourses,false);
        
        for(int i=0;i<numCourses;++i)
            if(!visited[i])
                dfs(adj,i,visited,mystack);
        
        while(!mystack.empty())
        {
            ans.push_back(mystack.top());
            mystack.pop();
        }
        return ans;
    }
};