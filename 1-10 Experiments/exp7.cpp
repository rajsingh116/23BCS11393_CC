class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX);

        queue<pair<int, int>> q;
        q.push({1, 0});
        dist1[1] = 0;

        while (!q.empty()) {
            auto [node, currTime] = q.front();
            q.pop();

            if ((currTime / change) % 2 == 1) {
                currTime = (currTime / change + 1) * change;
            }

            for (int nei : adj[node]) {
                int newTime = currTime + time;

                if (newTime < dist1[nei]) {
                    dist2[nei] = dist1[nei];
                    dist1[nei] = newTime;
                    q.push({nei, newTime});
                }

                else if (newTime > dist1[nei] && newTime < dist2[nei]) {
                    dist2[nei] = newTime;
                    q.push({nei, newTime});
                }
            }
        }

        return dist2[n];
    }
};