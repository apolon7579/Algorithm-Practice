#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int pattern1[10] = {1,2,3,4,5,1,2,3,4,5};
    int pattern2[8] = {2,1,2,3,2,4,2,5};
    int pattern3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    int cnt1 = 0; int cnt2 = 0; int cnt3 = 0;
    
    for(int i = 0; i < answers.size(); i++){
        
        if(pattern1[i % 10] == answers[i]) cnt1++;
        if(pattern2[i % 8] == answers[i]) cnt2++;
        if(pattern3[i % 10] == answers[i]) cnt3++;
    }
    
    int maxV = max(cnt1, max(cnt2, cnt3));
    
    if(maxV == cnt1) answer.push_back(1);
    if(maxV == cnt2) answer.push_back(2);
    if(maxV == cnt3) answer.push_back(3);
    
    return answer;
}
