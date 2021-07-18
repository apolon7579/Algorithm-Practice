#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000;

typedef struct {
    int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1,0}, {0, 1}, {0, -1} };

int N, M;
int graph[MAX][MAX];
int cache[MAX][MAX][2];

int bfs() {
    queue<pair<pair<int, int>, int>> q; // y, x , 벽뚫기 여부
    q.push({ {0, 0}, 1 });
    cache[0][0][1] = 1;

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;
        q.pop();

        // 도착할경우
        if (y == N - 1 && x == M - 1) return cache[y][x][block];
        
        for (int i = 0; i < 4; i++) {
            int nextY = y + moveDir[i].y;
            int nextX = x + moveDir[i].x;

            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {

                //벽이 있고, 벽을 아직 안 뚫었다면
                if (graph[nextY][nextX] == 1 && block) {
                    cache[nextY][nextX][block - 1] = cache[y][x][block]+1;
                    q.push({ {nextY, nextX}, block - 1 });
                }
                //벽이 없고, 아직 방문하지 않았던 곳이라면
                else if (graph[nextY][nextX] == 0 && cache[nextY][nextX][block] == 0) {
                    cache[nextY][nextX][block] = cache[y][x][block] + 1;
                    q.push({ {nextY, nextX}, block });
                }
            }
        }
    }

    return -1; // while문 빠져나올겨우
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < M; j++)
            graph[i][j] = temp[j] - '0';
    }

    cout << bfs() << "\n";

    return 0;
}
