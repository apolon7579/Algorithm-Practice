#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <cstdlib>
#include <list>
#include <unordered_map>

using namespace std;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> lottos = { 45, 4, 35, 20, 3, 9 }; // 구매한 로또번호
    vector<int> win_nums = { 20, 9, 3, 45, 4, 35 }; // 당첨번호

    int minV = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (lottos[i] == win_nums[j]) {
                minV++;
            }
        }
    }

    int maxV = minV;

    for (int i = 0; i < 6; i++) {
        if (lottos[i] == 0) maxV++;
    }

    if (minV == 6) {
        minV = 1;
    }
    else if (minV == 5) {
        minV = 2;
    }
    else if (minV == 4) {
        minV = 3;
    }
    else if (minV == 3) {
        minV = 4;
    }
    else if (minV == 2) {
        minV = 5;
    }
    else {
        minV = 6;
    }

    if (maxV == 6) {
        maxV = 1;
    }
    else if (maxV == 5) {
        maxV = 2;
    }
    else if (maxV == 4) {
        maxV = 3;
    }
    else if (maxV == 3) {
        maxV = 4;
    }
    else if (maxV == 2) {
        maxV = 5;
    }
    else {
        maxV = 6;
    }

    cout << maxV << minV;

    return 0;
}
