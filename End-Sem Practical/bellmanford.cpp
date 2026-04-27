#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    const int INF = 1e8;

    vector<int> dist(V, INF);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return {-1};
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V1 = 5, src1 = 0;
    vector<vector<int>> edges1 = {
        {1, 3, 2},
        {4, 3, -1},
        {2, 4, 1},
        {1, 2, 1},
        {0, 1, 5}
    };

    vector<int> result1 = bellmanFord(V1, edges1, src1);

    cout << "Test 1 Output: [";
    for (int i = 0; i < result1.size(); i++)
        cout << result1[i] << (i + 1 < result1.size() ? ", " : "");
    cout << "]\n";

  

    return 0;
}
