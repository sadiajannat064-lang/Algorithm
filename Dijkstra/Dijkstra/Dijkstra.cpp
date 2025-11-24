#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long LL;

typedef pair<int, int> PII;

typedef pair<LL, int> PLI;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;


    vector<PII> adj[n + 1];
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }


    const LL INF = 4e14;
    vector<LL> dist(n + 1, INF);

    vector<int> parent(n + 1, 0);


    priority_queue<PLI, vector<PLI>, greater<PLI>> pq;


    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        LL d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }


    if (dist[n] == INF) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        int curr = n;
        while (curr != 0) {
            path.push_back(curr);
            if (curr == 1) break;
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
