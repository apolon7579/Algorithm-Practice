#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    string ans = "";
    unordered_map<string, int> hash;

    for (string name : participant) {
        hash[name]++;
    }

    for (string name : completion) {
        hash[name]--;
    }

    for (auto pair : hash) {
        if (pair.second > 0) {
            ans = pair.first;
            break;
        }
    }

    return ans; 
    
}
