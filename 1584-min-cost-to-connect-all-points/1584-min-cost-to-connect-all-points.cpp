class Solution {
public:
    vector<vector<pair<int,int>>> builtAdjList(vector<vector<int>>& points){
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);

        for ( int i = 0 ; i < n ; ++i ){
            for ( int j = i+1 ; j < n ; ++j ){
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                adj[i].push_back({ weight , j });
                adj[j].push_back({ weight , i });
            }
        }

        return adj;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        if ( n == 0 ) return 0;

        vector<bool> inMST(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        vector<vector<pair<int,int>>> adj = builtAdjList(points);
        int minCost = 0;
        int nodesConnected = 0;

        minHeap.push({0, 0});

        while ( !minHeap.empty() && nodesConnected < n ){
            auto [ weight , currNode ] = minHeap.top();
            minHeap.pop();

            if ( inMST[currNode] ) continue;

            inMST[currNode] = true;
            minCost += weight;
            nodesConnected++;

            for ( auto& neighbour : adj[currNode] ){
                int weight = neighbour.first;
                int node = neighbour.second;

                if (inMST[node] == false){
                    minHeap.push({weight , node});
                }
            }
        }

        return minCost;
    }
};