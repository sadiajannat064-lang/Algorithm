
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

void solve() {
    int N, R;
    cin >> N >> R;

    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < R; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }


    vector<long long> d1(N + 1, INF);
    vector<long long> d2(N + 1, INF);


    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    d1[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long current_L = pq.top().first;
        int u = pq.top().second;
        pq.pop();


        if (current_L > d2[u]) {
            continue;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            long long new_L = current_L + w;


            if (new_L < d1[v]) {

                d2[v] = d1[v];
                d1[v] = new_L;

                pq.push({d1[v], v});
                if (d2[v] != INF) {
                    pq.push({d2[v], v});
                }
            }

            else if (new_L > d1[v] && new_L < d2[v]) {
                d2[v] = new_L;
                pq.push({d2[v], v});
            }
        }
    }

    cout << d2[N];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case " << t << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}

