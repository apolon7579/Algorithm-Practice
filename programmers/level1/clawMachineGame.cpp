#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

vector<vector<int>> board = {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 3},
    {0, 2, 5, 0, 1},
    {4, 2, 4, 4, 2},
    {3, 5, 1, 3, 1}
};

vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

int col = board.size(); 
int* heightCheck = new int[col];

void init() {

    for (int i = 0; i < col; i++) {
        heightCheck[i] = 0;
    }

    // 각 column별 높이 체크
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < col; j++) {
            if (board[j][i] != 0) {
                heightCheck[i] = col - j;
                j = 0; break;
            }
        }
    }
}

int solution() {
    int ans = 0;

    stack<int> st;

    for (int i = 0; i < moves.size(); i++) {

        int top = 0;
        if (!st.empty()) top = st.top();

        int idx, doll = 0;
        if (heightCheck[moves[i] - 1] != 0) {
            idx = col - heightCheck[moves[i] - 1];
            doll = board[idx][moves[i] - 1];
        }

        if(heightCheck[moves[i]-1] != 0)
            heightCheck[moves[i]-1] = heightCheck[moves[i]-1] - 1;

        if (doll != 0) {
            if (top == doll) {
                st.pop(); ans += 2;
            }
            else {
                st.push(doll);
            }         
        }

    }

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    cout << solution();

    return 0;
}
