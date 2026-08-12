class Solution {
public:
    vector<int> dijkstra(int n, int k, const vector<vector<pair<int, int>>>& adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minQ;
        
        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        minQ.push({0, k});

        while (!minQ.empty()) {
            auto [dis, u] = minQ.top();
            minQ.pop();

            if (dis > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    minQ.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist = dijkstra(n, k, adj);

        int max_time = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }
};