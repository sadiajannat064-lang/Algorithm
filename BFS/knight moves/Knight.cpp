#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;

struct Square {
    int r, c, dist;
};

const int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};


pair<int, int> to_coords(const string& sq) {

    int c = sq[0] - 'a';

    int r = sq[1] - '1';
    return {r, c};
}


int bfs(const string& start_sq, const string& end_sq) {
    pair<int, int> start_pos = to_coords(start_sq);
    pair<int, int> end_pos = to_coords(end_sq);

    int start_r = start_pos.first;
    int start_c = start_pos.second;
    int end_r = end_pos.first;
    int end_c = end_pos.second;

    if (start_r == end_r && start_c == end_c) {
        return 0;
    }


    int dist[8][8];
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;

    dist[start_r][start_c] = 0;
    q.push({start_r, start_c});

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int r = current.first;
        int c = current.second;
        int current_dist = dist[r][c];

        for (int i = 0; i < 8; ++i) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];


            if (next_r >= 0 && next_r < 8 && next_c >= 0 && next_c < 8) {

                if (dist[next_r][next_c] == -1) {
                    dist[next_r][next_c] = current_dist + 1;


                    if (next_r == end_r && next_c == end_c) {
                        return dist[next_r][next_c];
                    }

                    q.push({next_r, next_c});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    while (cin >> a >> b) {
        int moves = bfs(a, b);
        cout << "To get from " << a << " to " << b << " takes " << moves << " knight moves." << endl;
    }

    return 0;
}
