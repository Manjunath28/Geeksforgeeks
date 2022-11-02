 public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
       int n = grid.size() , m = grid[0].size();

        queue<pair<int,pair<int,int>>> q;

        vector<vector<int>> dist(n,vector<int>(m,1e9));

        q.push({0,source});

        dist[source.first][source.second] = 0;

        //If the sourceand destination is same then we need a distance of  0

        if(source.first==destination.first && source.second==destination.second) return 0;

        while(!q.empty()){

            int dis = q.front().first;

            int r = q.front().second.first;

            int col = q.front().second.second;

            q.pop();

            int drow[]={-1,0,1,0};

            int dcol[]={0,1,0,-1};

            for(int i=0;i<4;i++){

                int nrow = r + drow[i];

                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] ==1){

                    if(dis+1 < dist[nrow][ncol]){

                        

                        dist[nrow][ncol] = dis+1;

                        q.push({dist[nrow][ncol],{nrow,ncol}});

                    

                        if(nrow == destination.first && ncol == destination.second)

                            return dist[nrow][ncol];

                    }

                }
            }
        }

        return -1;

    }
