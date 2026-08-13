class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int, int>> adj[n+1];
        for(auto it:flights)
        {
            int u= it[0];
            int v =it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int , int>>>>pq;

        pq.push({0, {0, src}});


        vector<int>dist(n+1,1e9);
        dist[src]=0;


        while(pq.empty()==false)
        {
            int stops = pq.top().first;
            int distance= pq.top().second.first;
            int node = pq.top().second.second;
            // if(node== dst) return distance;
            pq.pop();


            for(auto it:adj[node])
            {
                int d = distance+it.second;
                if(stops <=k and dist[it.first] > d)
                {
                    dist[it.first]=d;
                    pq.push({stops+1 , {d , it.first}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};
