#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> ans;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> cmd = commands[i];
        int start = cmd[0]; int end = cmd[1]; int idx = cmd[2];

        vector<int> temp;
        for (int j = start; j <= end; j++) {
            temp.push_back(array[j-1]);
        }

        sort(temp.begin(), temp.end());
        ans.push_back(temp[idx - 1]);
    }

    return ans;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = { 1,5,2,6,3,7,4 }; 
    vector<vector<int>> comm = {
        {2,5,3}, {4,4,1}, {1,7,3}
    };

    vector<int> ansList = solution(arr, comm);

    return 0;
}
