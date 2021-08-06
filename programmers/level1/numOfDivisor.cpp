#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <cstdlib>
#include <list>
#include <cmath>
#include <unordered_map>

using namespace std;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int left = 24; int right = 27;

    int sum = 0;

    for (int i = left; i <= right; i++) {
        int k = 2; unordered_map<int, int> map;
        int num = i;
        while (num != 1) {
            if (num % k == 0) {
                map[k]++;
                num /= k;
            }
            else {
                k++;
            }
        }

        int cnt = 1;

        for (auto val : map) {
            cnt *= 1 + val.second;
        }

        if (cnt % 2 == 0) {
            sum += i;
        }
        else {
            sum -= i;
        }
    }

    cout << sum;

    return 0;
}
