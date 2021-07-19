
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[300][300] = { false, };

struct knight {
    int y, x;
};

knight moveDir[8] = { {1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1} };
int tCase; int length;
int y, x, depth;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tCase;

    for (int i = 0; i < tCase; i++) {
        fill(&visited[0][0], &visited[299][300], false);

        cin >> length;
        struct knight start; struct knight dest;
        cin >> start.x >> start.y >> dest.x >> dest.y;

        queue<pair<knight, int>> q; // knight의 위치, depth를 담음
        q.push({ {start.y, start.x}, 0 });
        visited[0][0] = true;

        while (!q.empty()) {
            y = q.front().first.y;
            x = q.front().first.x;
            depth = q.front().second;

            if (y == dest.y && x == dest.x) {
                break;
            }

            q.pop();

            for (int i = 0; i < 8; i++) {
                int ny = y + moveDir[i].y;
                int nx = x + moveDir[i].x;

                if (0 <= ny && ny < length && 0 <= nx && nx < length && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push({ {ny, nx}, depth + 1 });
                }
            }
        }

        cout << depth << "\n";
    }

    return 0;
}
