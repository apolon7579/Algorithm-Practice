#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct tomato {
    int y, x, z;
};

queue<tomato> q;

int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };

int n, m, h,result = 0;
int graph[101][101][101];

void bfs() {
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int z = q.front().z;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nh = z + dh[i];

            if (0 <= nx && 0 <= ny && 0 <= nh && nx < m && ny < n && nh < h && graph[ny][nx][nh] == 0) {
                graph[ny][nx][nh] = graph[y][x][z] + 1;
                q.push({ ny, nx, nh });
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> h; // m : 가로, n : 세로, h : 높이

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> graph[i][j][k];
                if (graph[i][j][k] == 1)
                    q.push({ i, j, k });
            }
        }
    }

    bfs();

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j][k] == 0) {
                    cout << "-1\n";
                    return 0;
                }

                if (result < graph[i][j][k]) {
                    result = graph[i][j][k];
                }
            }
        }
    }

    cout << result - 1 << "\n";

    return 0;
}
