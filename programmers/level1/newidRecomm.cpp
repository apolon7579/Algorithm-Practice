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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string new_id = "abcdefghijklmn.p";

    // 1. to_lowercase
    for_each(new_id.begin(), new_id.end(), [](char& c) {
        c = ::tolower(c);
     });

    // 2. special character erase
    for (int i = 0; i < new_id.length(); ) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
            || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            i++;
            continue;
        }

        new_id.erase(new_id.begin() + i);
    }
    
    //3. remove duplicate
    for (int i = 0; i < new_id.length() - 1; i++) {
        if ((new_id[i] == '.' && '.' == new_id[i + 1])) {
            new_id.erase(new_id.begin() + i);
            i--;
        }

    }
    
    //4 if there is dot in front of str or back remove
    if (new_id[0] == '.') new_id.erase(new_id.begin());
    if (new_id[new_id.length() - 1] == '.') new_id.erase(new_id.end() - 1);

    //5. space check
    if (new_id.length() == 0) new_id.push_back('a');

    //6. length check
    if (new_id.length() >= 16) new_id.erase(new_id.begin() + 15, new_id.end());

    //7. length check2
    if (new_id.length() <= 2) {
        while (new_id.length() != 3) {
            new_id.push_back(new_id[new_id.length() - 1]);
        }
    }

    //4 if there is dot in front of str or back remove
    if (new_id[0] == '.') new_id.erase(new_id.begin());
    if (new_id[new_id.length() - 1] == '.') new_id.erase(new_id.end() - 1);

    cout << new_id;


    return 0;
}
