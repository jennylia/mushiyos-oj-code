/*Filename: d041.cpp
 *Author: Mushiyo
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool lexicographicalCmp(const char &c1, const char &c2) {
	char lowerC1 = tolower(c1);
	char lowerC2 = tolower(c2);

	if (lowerC1 == lowerC2) {
		if (c1 < 'a') { // c1 between A - Z
			return false;
		} else {
			return true;
		}
	} else {
		return lowerC1 < lowerC2;
	}
}

int main() {
	char cstr[100];

	while (scanf("%s ", &cstr) == 1) {
		int len = strlen(cstr);

/*		if(len == 0){
//			printf("\n");
//			continue;
//		}
*/
		sort(cstr, cstr + len, lexicographicalCmp);

		printf("%s\n", cstr);
	}

	return 0;
}
