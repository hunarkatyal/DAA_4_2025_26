#include <bits/stdc++.h>
using namespace std;


int tsp(vector<vector<int>>& cost){
    int n = cost.size();
    int FULL = (1 << n) - 1;

    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));

    dp[1][0] = 0;

    for (int mask = 1; mask <= FULL; mask++) {
        for (int u = 0; u < n; u++) {
            if (dp[mask][u] == INT_MAX) 
                continue;
            if (!(mask >> u & 1)) 
                continue;

            for (int v = 0; v < n; v++) {
                if (mask >> v & 1) 
                    continue; 
                int new_mask = mask | (1 << v);

                dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + cost[u][v]);
            }
        }
    }

    int result = INT_MAX;
    for (int u = 1; u < n; u++) {
        if (dp[FULL][u] != INT_MAX)
            result = min(result, dp[FULL][u] + cost[u][0]);
    }

    return result;


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> cost1 = {
        {0, 111},
        {112, 0}
    };
    cout << "Output: " << tsp(cost1) << endl;

    return 0;
}
