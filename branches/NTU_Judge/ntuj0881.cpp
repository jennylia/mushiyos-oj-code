/*Filename: ntuj0881.cpp
 *Author: Mushiyo
 */

#include <iostream>
#include <stdio.h>
#include <climits>
#include <cmath>

using namespace std;

int main() {
	int n = 0, m = 0;

	while (scanf("%d %d", &n, &m) == 2) {
		int drink[n + 1];

		drink[0] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &drink[i]);
		}

		int satisficationSum[n];
		satisficationSum[0] = drink[0];
		for (int i = 1; i <= n; ++i) {
			satisficationSum[i] = drink[i] + satisficationSum[i - 1];
		}

		while (m > 0) {
			int op = 0, a = 0, b = 0;
			scanf("%d %d %d", &op, &a, &b);

			if (op == 1) {
				int maxSum = INT_MIN;
				int minSum = 0;
				for (int i = a; i <= b; ++i) {
					maxSum = max(maxSum, satisficationSum[i] - minSum - satisficationSum[a - 1]);
					minSum = min(minSum, satisficationSum[i] - satisficationSum[a - 1]);
				}

				printf("%d\n", maxSum);
			} else {
				int diff = b - drink[a];
				for (int i = a; i <= n; ++i) {
					satisficationSum[i] += diff;
				}
			}

			--m;
		}
	}

	return 0;
}
