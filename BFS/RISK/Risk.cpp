#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <sstream>

using namespace std;

const int NUM_COUNTRIES = 20;

int bfs_shortest_path(int start, int destination, const vector<int> adj[]) {

    if (start == destination) {
        return 0;
    }


    vector<int> dist(NUM_COUNTRIES + 1, -1);


    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;

                if (v == destination) {
                    return dist[v];
                }

                q.push(v);
            }
        }
    }


    return -1;
}


bool solve() {

    vector<int> adj[NUM_COUNTRIES + 1];


    for (int i = 1; i < NUM_COUNTRIES; ++i) {
        int X;
        if (!(cin >> X)) {
            return false;
        }

        for (int j = 0; j < X; ++j) {
            int J;
            if (!(cin >> J)) return false;

            adj[i].push_back(J);
            adj[J].push_back(i);
        }
    }


    int N;
    if (!(cin >> N)) {
        return false;
    }

    static int test_set_count = 0;
    test_set_count++;


    cout << "Test Set #" << test_set_count << endl;

    for (int k = 0; k < N; ++k) {
        int A, B;
        if (!(cin >> A >> B)) return false;


        int result = bfs_shortest_path(A, B, adj);


        cout << setw(2) << right << A
             << " to "
             << setw(2) << right << B
             << ": "
             << left << result
             << endl;
    }


    cout << endl;

    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    while (solve()) {
    }

    return 0;
}
