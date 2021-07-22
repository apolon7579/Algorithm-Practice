#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

// 키패드 배열
char keypad[4][3] = { 
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

//배열로부터 인덱스 계산
pair<int, int> findIndex(char key) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 3; x++) {
            if (keypad[y][x] == key)
                return { y, x };
        }
    }
}

string solution(vector<int> numbers, string hand) {
    string ans = "";

    char curLeft = '*'; char curRight = '#'; // 처음 손가락위치 초기화

    //조건에 맞게 손가락 위치를 계속 갱신해준다
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            ans += 'L';
            curLeft = '0' + numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            ans += 'R';
            curRight = '0' + numbers[i];
        }
        else {
            //2 5 8 0 을 다룰때는 택시기하학 거리공식을 사용해서 거리 계산 비교후 값을 채워넣는다
            pair<int, int> coordLeft = findIndex(curLeft);
            pair<int, int> coordRight = findIndex(curRight);
            pair<int, int> coordCur = findIndex('0' + numbers[i]);

            int leftDist = abs(coordCur.first - coordLeft.first) + abs(coordCur.second - coordLeft.second);
            int rightDist = abs(coordCur.first - coordRight.first) + abs(coordCur.second - coordRight.second);

            if (leftDist < rightDist) {
                ans += 'L';
                curLeft = '0' + numbers[i];
            }
            else if (leftDist == rightDist) {
                if (hand == "left") {
                    ans += 'L';
                    curLeft = '0' + numbers[i];
                }
                else if(hand == "right"){
                    ans += 'R';
                    curRight = '0' + numbers[i];
                }
            }
            else if(leftDist > rightDist){
                ans += 'R';
                curRight = '0' + numbers[i];
            }
        }
    }

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string hand = "left";

    cout << solution(numbers, hand);

    return 0;
}
