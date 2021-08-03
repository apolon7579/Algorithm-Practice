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
using namespace stdext;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const char* s = "123";
    string str = s;

    string ans;

    for (int i = 0; i < str.size(); i++) {
        if (48 <= str[i] && str[i] <= 57) {
            ans += str[i];
        }
        else {
            if (str[i] == 'z') {
                i += 3;
                ans += '0';
            }
            else if (str[i] == 'o') {
                i += 2;
                ans += '1';
            }
            else if (str[i] == 't') {
                if (str[i + 1] == 'w') {
                    i += 2;
                    ans += '2';
                }
                else if (str[i + 1] == 'h') {
                    i += 4;
                    ans += '3';
                }
            }
            else if (str[i] == 'f') {
                if (str[i + 1] == 'o') {
                    i += 3;
                    ans += '4';
                }
                else if (str[i + 1] == 'i') {
                    i += 3;
                    ans += '5';
                }
            }
            else if (str[i] == 's') {
                if (str[i + 1] == 'i') {
                    i += 2;
                    ans += '6';
                }
                else if (str[i + 1] == 'e') {
                    i += 4;
                    ans += '7';
                }
            }
            else if (str[i] == 'e') {
                i += 4;
                ans += '8';
            }
            else if (str[i] == 'n') {
                i += 3;
                ans += '9';
            }
        }
    }

    cout << stoi(ans);

    return 0;
}
