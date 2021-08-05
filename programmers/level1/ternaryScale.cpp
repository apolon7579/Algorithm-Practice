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

    vector<int> arr;

    int n = 45;

    while (n != 0) {
        int remainder = n % 3;
        n = n / 3;
        arr.push_back(remainder);
    }

    int num = 0;
    int size = arr.size() - 1;
    for (auto val : arr) {
        num += pow(3, size) * val;
        size--;
    }

    cout << num;

    return 0;
}
