class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // dist[node][consecutive_count]
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        // {distance, node, consecutive_count}
        using T = tuple<int,int,int>;

        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {

            auto [d, u, cnt] = pq.top();
            pq.pop();

            // Ignore outdated states
            if(d != dist[u][cnt])
                continue;

            // Destination reached
            if(u == n - 1)
                return d;

            for(auto &[v, w] : adj[u]) {

                int newCnt;

                if(labels[u] == labels[v])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                if(newCnt > k)
                    continue;

                int newDist = d + w;

                if(newDist < dist[v][newCnt]) {

                    dist[v][newCnt] = newDist;

                    pq.push({newDist, v, newCnt});
                }
            }
        }

        return -1;
    }
};