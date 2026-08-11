class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n= numCourses;

        vector<int>adj[n];
        vector<int>indegree(n, 0);
        for(auto it:prerequisites)
        {
            int u= it[0];
            int v =it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int>temp;
        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();
            temp.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }

        return temp.size()==n;
    }
};
