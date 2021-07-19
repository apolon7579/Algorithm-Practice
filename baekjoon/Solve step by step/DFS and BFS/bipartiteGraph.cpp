
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int tCase, vertex, edge;
vector<int> graph[20001];
int visited[20001]; // 0 : 미방문 1 : Red 2: Blue

void bfs(int start) {
    queue<int> q;
    int color = 1;

    visited[start] = color;
    q.push(start);
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (visited[now] == 1) {
            color = 2;
        }
        else if (visited[now] == 2) {
            color = 1;
        }

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if (!visited[next]) { // 미방문 상태(0)만 검사하기때문에 이분그래프가 아니라면 정점을 다시 색칠하게됨
                visited[next] = color;
                q.push(next);
            }
        }
    }   
}

bool check() {
    for (int i = 1; i <= vertex; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int next = graph[i][j];
            if (visited[i] == visited[next]) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tCase;

    for (int i = 0; i < tCase; i++) {
        cin >> vertex >> edge;

        for (int i = 0; i < edge; i++) {
            int first, last;
            cin >> first >> last;
            graph[first].push_back(last);
            graph[last].push_back(first);
        }

        for (int i = 1; i <= vertex; i++) {
            if (!visited[i]) bfs(i);
        }

        if (check()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

        for (int i = 0; i <= vertex; i++) {
            graph[i].clear();
        }
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}
