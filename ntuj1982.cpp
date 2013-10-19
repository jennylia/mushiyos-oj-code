/*Filename: ntuj1982.cpp
 *Author: Mushiyo
 */

#include <iostream>
#include <set>

using namespace std;

int main() {
	const int MAX_SIZE = 4000;
	int A[MAX_SIZE];
	int B[MAX_SIZE];
	int C[MAX_SIZE];
	int D[MAX_SIZE];

	int n = 0;

	while (cin >> n) {
		set<int> cPlusD;
		for (int i = 0; i < n; ++i) {
			cin >> A[i] >> B[i] >> C[i] >> D[i];
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cPlusD.insert(-(C[i] + D[j]));
			}
		}

		int countSum0 = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (cPlusD.find(A[i] + B[j]) != cPlusD.end()) {
					++countSum0;
				}
			}
		}

		cout << countSum0 << endl;
	}

	return 0;
}
