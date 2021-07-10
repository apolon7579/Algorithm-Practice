#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

int memory[101];
int cost[101];
int dp[10001]; 
int sum;

int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &memory[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
        sum += cost[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = sum ; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
        }
    }

    int i = 0;
    for (i = 0; i < sum, dp[i] < m; i++);
    printf("%d", i);

    return 0;
}
