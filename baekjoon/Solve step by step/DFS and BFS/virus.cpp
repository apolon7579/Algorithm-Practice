#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;

void dfs(int start, vector<int> graph[], bool check[]) {
    check[start] = true;


    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];

        if (check[next] == false) {
            cnt++;
            dfs(next, graph, check);
        }
    }
}

int main() {
    
    int n, m, start;
    scanf("%d %d", &n, &m); // n : 정점, m : 간선
    start = 1;

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

    printf("%d\n", cnt);

    return 0;
}
