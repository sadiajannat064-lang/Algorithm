
#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // For memset

using namespace std;

// Function to perform BFS and check for bicoloring
bool isBicolorable(int n, const vector<int> adj[]) {
    // We use a color array: 0 = uncolored, 1 = Color A, 2 = Color B
    int color[200];

    // Initialize all nodes as uncolored
    // Note: The problem guarantees 1 < n < 200, so we only need to clear up to n-1
    memset(color, 0, sizeof(color));

    // The graph is guaranteed to be strongly connected, so we only need one BFS,
    // starting from an arbitrary node (Node 0 is always safe since n > 1)

    queue<int> q;

    // Start with Node 0, assign it Color A (1)
    color[0] = 1;
    q.push(0);

    // Standard Breadth-First Search (BFS)
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Iterate through all neighbors v of u
        for (int v : adj[u]) {

            // Case 1: Neighbor v is uncolored (color[v] == 0)
            if (color[v] == 0) {
                // Assign v the opposite color of u
                // If u is 1, v becomes 2. If u is 2, v becomes 1.
                color[v] = (color[u] == 1) ? 2 : 1;
                q.push(v);
            }
            // Case 2: Neighbor v is already colored
            else if (color[v] == color[u]) {
                // Conflict! Found an edge between two nodes of the same color.
                // This means the graph contains an odd-length cycle, and is NOT bicolorable (not bipartite).
                return false;
            }
            // Case 3 (Implicit): color[v] is different from color[u] - this is correct/consistent.
        }
    }

    // If the entire graph was traversed without finding any conflicts,
    // it is bicolorable (bipartite).
    return true;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;


    while (cin >> n && n != 0) {

        int l;
        cin >> l;


        vector<int> adj[200];


        for (int i = 0; i < l; ++i) {
            int u, v;
            cin >> u >> v;


            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        if (isBicolorable(n, adj)) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}
