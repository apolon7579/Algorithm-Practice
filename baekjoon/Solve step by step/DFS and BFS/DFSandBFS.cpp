#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int start, vector<int> graph[], bool check[]) {
    check[start] = true;
    printf("%d ", start);

    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];

        if (check[next] == false) {
            dfs(next, graph, check);
        }
    }
}

void bfs(int start, vector<int> graph[], bool check[]) {
    queue<int> q;
    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        printf("%d ", tmp);
        for (int i = 0; i < graph[tmp].size(); i++) {
            if (check[graph[tmp][i]] == false) {
                q.push(graph[tmp][i]);
                check[graph[tmp][i]] = true;
            }
        }
    }
}

int main() {
    
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start); // n : 정점, m : 간선

    vector<int>* graph = new vector<int>[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v; //간선 시작, 간선 끝
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    bool* check = new bool[n + 1];
    fill(check, check + n + 1, false);

    dfs(start, graph, check);

    fill(check, check + n + 1, false);

    printf("\n");

    bfs(start, graph, check);

    return 0;
}
