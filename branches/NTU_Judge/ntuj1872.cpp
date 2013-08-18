/*Filename: ntuj1872.cpp
 *Author: Mushiyo
 */

#include <iostream>
#include <vector>
#define RED true

using namespace std;

const int SIZE = 1000 + 2;
bool stageMap[SIZE][SIZE];
bool ableMap[SIZE][SIZE];

void outterInit() {
	for (int i = 0; i < SIZE; ++i) {
		stageMap[0][i] = RED;
		stageMap[SIZE - 1][i] = RED;
		stageMap[i][0] = RED;
		stageMap[i][SIZE - 1] = RED;

		ableMap[0][i] = false;
		ableMap[SIZE - 1][i] = false;
		ableMap[i][0] = false;
		ableMap[i][SIZE - 1] = false;
	}
}

void innerInit(int n, int m) {
	// initialize the left boarder
	for (int i = 1; i <= n + 1; ++i) {
		ableMap[m + 1][i] = false;
	}

	// initialize the bottom boarder
	for (int i = 1; i <= m + 1; ++i) {
		ableMap[n + 1][i] = false;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			ableMap[i][j] = true;
		}
	}
}

int main() {
	int T = 0;

	outterInit();

	while (cin >> T) {
		while (T > 0) {
			int N = 0, M = 0, K = 0;
			cin >> N >> M >> K;

			innerInit(N, M);

			vector<int> redX[K];
			vector<int> redY[K];
			for (int i = 0; i < K; ++i) {
				int X = 0, Y = 0;
				cin >> X >> Y;

				for (int j = 0; j < X; ++j) {
					int tmp = 0;
					cin >> tmp;
					redX[i].push_back(tmp);
				}

				for (int j = 0; j < Y; ++j) {
					int tmp = 0;
					cin >> tmp;
					redY[i].push_back(tmp);
				}
			}

			for(int i = K - 1; i >= 0; --i){
				for(int j = 0; j < redX[i].size(); ++j){
					for(int col = 1; col <= M; ++col){
						stageMap[redX[i][j]][col] = RED;
					}
				}
			}

			--T;
		}
	}

	return 0;
}
