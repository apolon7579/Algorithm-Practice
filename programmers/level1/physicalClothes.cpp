#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <cstdlib>
#include <list>

using namespace std;

int n = 10;
vector<int> lost = { 1, 3, 4 };
vector<int> reserve = {3, 5, 6 };


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    int cnt = n - lost.size();
    int lostV = 0;

    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                lost[i] = -1;
                reserve[j] = -1;
                lostV++;
                break;
            }
        }
    }

    cnt += lostV;

    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] - 1 == lost[i]) {
                reserve[j] = -1;
                cnt++;
                break;
            }
            else if (reserve[j] + 1 == lost[i]) {
                reserve[j] = -1;
                cnt++;
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}
