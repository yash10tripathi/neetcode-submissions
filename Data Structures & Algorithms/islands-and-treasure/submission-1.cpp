class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        long long inf= 2147483647;
        int n= grid.size();
        int m= grid[0].size();

        queue<pair<int, int>> q;
        for( int i=0 ;i<n;i++)
        {
            for( int j=0; j<m ;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({ i, j});
                }
            }
        }


        while(q.empty()==false)
        {
            int i= q.front().first;
            int j= q.front().second;

            q.pop();

            int dx[4]= {-1,1,0,0};
            int dy[4]= {0,0,-1,1};

            for(int k=0; k<4; k++)
            {
                int nx = i+dx[k];
                int ny= j+dy[k];

                if(nx>=0 and nx< n and ny>=0 and ny<m and grid[nx][ny]==inf and grid[nx][ny]> grid[i][j]+1)
                {
                    grid[nx][ny]=grid[i][j]+1;
                    q.push({nx, ny});
                }
            }
        }

        

        // return grid;
    }
};
