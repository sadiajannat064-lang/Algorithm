#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max() / 2;

struct Edge {
    int from;
    int to;
    int time;
};

void solve(int case_num) {
    int N, M;
    if (!(cin >> N >> M)) return;

    vector<Edge> edges;
    for (int i = 0; i < M; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        edges.push_back({x, y, t});
    }

    vector<long long> dist(N, INF);
    dist[0] = 0;

    for (int i = 0; i < N - 1; ++i) {
        bool updated = false;
        for (const auto& edge : edges) {
            if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.time) {
                dist[edge.to] = dist[edge.from] + edge.time;
                updated = true;
            }
        }
        if (!updated) break;
    }

    bool negative_cycle = false;
    for (const auto& edge : edges) {
        if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.time) {
            negative_cycle = true;
            break;
        }
    }

    cout << "Case " << case_num << ": ";
    if (negative_cycle) {
        cout << "possible" << "\n";
    } else {
        cout << "not possible" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    if (!(cin >> c)) return 0;
    for (int i = 1; i <= c; ++i) {
        solve(i);
    }

    return 0;
}
