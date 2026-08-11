class Disjointset {
    public:
    vector<int>parent;
    vector<int>size;

    Disjointset( int n)
    {
        parent.resize(n+1 ,0);
        size.resize(n+1 ,0);
        for( int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    int ultpar(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]= ultpar(parent[node]);
    }


    void unionbysize(int u, int v)
    {
        int up = ultpar(u);
        int vp= ultpar(v);
        if(up==vp) return;

        if(size[up] < size[vp])
        {
            parent[up]= vp;
            size[vp]+=up;
        }
        else
        {
            parent[vp]=up;
            size[up]+=vp;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        Disjointset ds(n);

        vector<int>ans;
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int par1 = ds.ultpar(u);
            int par2 = ds.ultpar(v);
            if(par1==par2)
            {
                ans= it;
            }
            else ds.unionbysize(u,v);
        }


        return ans;
        
    }
};
