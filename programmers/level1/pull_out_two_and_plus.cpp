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

vector<int> solutions;

void Combination(vector<int> numbers, vector<int> comb, int index, int depth) {
    if (depth == comb.size()) {

        int num = 0;

        for (int i = 0; i < comb.size(); i++) {
            num += comb[i];
        }

        solutions.push_back(num);

        return;
    }
    else {
        for (int i = index; i < numbers.size(); i++) {
            comb[depth] = numbers[i];
            Combination(numbers, comb, i + 1, depth + 1);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> numbers = { 5, 0, 2, 7 };
    vector<int> comb(2);

    Combination(numbers, comb, 0, 0);

    sort(solutions.begin(), solutions.end());
    solutions.erase(unique(solutions.begin(), solutions.end()), solutions.end());

    return 0;
}
