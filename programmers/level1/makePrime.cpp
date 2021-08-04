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

int cnt = 0;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void Combination(vector<int> nums, vector<int> comb, int index, int depth) {
    
    if (depth == comb.size()) {
        int temp = 0;
        for (int i = 0; i < comb.size(); i++) {
            temp += comb[i];
        }

        if (isPrime(temp)) cnt++;

        return;
    }
    else {
        for (int i = index; i < nums.size(); i++) {
            comb[depth] = nums[i];
            Combination(nums, comb, i + 1, depth + 1);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec = { 1, 2, 7, 6, 4}; // n = 5;

    vector<int> comb(3);

    Combination(vec, comb, 0, 0);

    cout << cnt;

    return 0;
}
