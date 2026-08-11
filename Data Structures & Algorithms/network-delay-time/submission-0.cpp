class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> adj(n);


        for(auto it:times)
        {
            int u= it[0]-1;
            int v= it[1]-1;
            int t= it[2];
            adj[u].push_back({v, t});
        }


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int>dist(n, 1e9);
        int src=k-1;
        dist[src]=0;

        pq.push({0, src});

        while(pq.empty()==false)
        {
            int node= pq.top().second;
            int dis= pq.top().first;

            pq.pop();

            for(auto it:adj[node])
            {
                int anode= it.first;
                int w = it.second;
                if(dist[anode] > dis+w)
                {
                    dist[anode]= dis+w;
                    pq.push({dis+w, anode});
                }
            }
        }

        int maxt =0;
        for(auto it:dist)
        {
            maxt= max(maxt, it);
        }
        for(auto it: dist) cout << it<<" ";
        cout << endl;
        if(maxt==1e9) return -1;
        return maxt;

    }
};
