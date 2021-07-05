#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int N, M;
int arr[2001];
bool dp[2001][2001];

void palindrome() {
    for (int i = 1; i <= N; i++)
        dp[i][i] = true;

    for (int i = 1; i < N; i++)
        if (arr[i] == arr[i + 1])
            dp[i][i + 1] = true;

    //dp[s][e] 는 s부터 e까지 펠린드롬인지 아닌지 dp[s][e]는 양 끝값 같음 &&, dp[s+1][e-1]를 만족시켜야함

    for (int i = 2; i < N; i++)
        for (int j = 1; j <= N - i; j++)
            if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
                dp[j][j + i] = true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    cin >> M;
    memset(dp, false, sizeof(dp));
    palindrome();

    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << "\n";
    }

    return 0;
}



