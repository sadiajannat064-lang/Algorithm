#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

const long long INF = 1e15;

struct Edge {
    int u, v;
    long long cost;
};

long long calculate_cost(int busyness_a, int busyness_b) {
    long long diff = (long long)busyness_b - busyness_a;
    return diff * diff * diff;
}

void solve() {
    int n;
    int test_set = 1;

    while (cin >> n) {
        vector<int> busyness(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> busyness[i];
        }

        int r;
        cin >> r;

        vector<Edge> edges;
        for (int i = 0; i < r; ++i) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v, calculate_cost(busyness[u], busyness[v])});
        }

        vector<long long> dist(n + 1, INF);
        vector<bool> in_negative_cycle(n + 1, false);

        dist[1] = 0;

        for (int i = 1; i <= n - 1; ++i) {
            for (const auto& edge : edges) {
                if (dist[edge.u] != INF && dist[edge.u] + edge.cost < dist[edge.v]) {
                    dist[edge.v] = dist[edge.u] + edge.cost;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (const auto& edge : edges) {
                if (dist[edge.u] != INF && dist[edge.u] + edge.cost < dist[edge.v] && !in_negative_cycle[edge.v]) {
                    in_negative_cycle[edge.v] = true;
                    dist[edge.v] = dist[edge.u] + edge.cost;
                }

                if (in_negative_cycle[edge.u]) {
                    in_negative_cycle[edge.v] = true;
                }
            }
        }

        int q;
        cin >> q;

        cout << "Set #" << test_set++ << endl;

        for (int i = 0; i < q; ++i) {
            int query_junction;
            cin >> query_junction;

            long long min_earning = dist[query_junction];

            if (dist[query_junction] == INF || in_negative_cycle[query_junction]) {
                cout << "?" << endl;
            } else if (min_earning < 3) {
                cout << "?" << endl;
            } else {
                cout << min_earning << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
