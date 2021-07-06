#include <iostream>
#include <cmath>

using namespace std;

int numOfWeight, numOfMarble; // 추 개수, 구슬 개수
int weight[30]; // 추 무게
int marble[7]; // 구슬 무게
bool visit[31][15001]; // 추의 개수와 추의 개수로 만들수 있는 무게 추의 최대무게는 500, 최대개수는 30이므로 30 x 500 + 1
//[n]개의 추로 m의 무개를 측정할수 있는지 나타냄

void calc(int cntWeight, int sumWeight) { // 추의 개수, 만들어낸 무게
	// 모든 경우를 검사하되 입력된 추의 개수를 넘어가면 종료	
	if (cntWeight > numOfWeight)
		return;
	if (visit[cntWeight][sumWeight] == true) // 이미 검사한경우 넘어감
		return;

	visit[cntWeight][sumWeight] = true;

	//추를 한개 증가시킬때마다 3개의 연산 비교

	calc(cntWeight + 1, sumWeight + weight[cntWeight]); // 구슬 반대편에 추를 올리는 경우
	calc(cntWeight + 1, sumWeight); // 추의 개수를 증가시키지만 아무런 무게도 더해주지 않는경우
	calc(cntWeight + 1, abs(sumWeight - weight[cntWeight])); // 추가한 추를 구슬과 같은쪽에 올리는 경우
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> numOfWeight;
	for (int i = 0; i < numOfWeight; i++)
		cin >> weight[i];

	cin >> numOfMarble;
	for (int i = 0; i < numOfMarble; i++)
		cin >> marble[i];

	calc(0, 0);
	for (int i = 0; i < numOfMarble; i++) {
		if (marble[i] > 1500) cout << "N ";
		else if (visit[numOfWeight][marble[i]] == true) cout << "Y ";
		else cout << "N ";
	}
	cout << "\n";

	return 0;
}