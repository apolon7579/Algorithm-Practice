#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1}; // 상 하 좌 우
int dy[4] = { 1, -1, 0, 0 };

int T;
int field[50][50] = { 0, };
bool check[50][50];
int M, N, K; // 가로, 세로, 입력

void dfs(int y, int x) {
    check[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int newY = y + dy[i];
        int newX = x + dx[i];

        if (0 <= newX && newX < M && 0 <= newY && newY < N) {
            if (field[newY][newX] == 1 && !check[newY][newX])
                dfs(newY, newX);
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;

        memset(field, 0, sizeof(field));
        memset(check, 0, sizeof(check));

        for (int j = 0; j < K; j++) {
            int x, y; cin >> x >> y;
            field[y][x] = 1;
        }

        int ans = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (field[i][j] == 1 && !check[i][j]) {
                    ans++;
                    dfs(i, j);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}