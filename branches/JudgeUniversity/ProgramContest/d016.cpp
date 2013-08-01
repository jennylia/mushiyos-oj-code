/*Filename: d016.cpp
 *Author: Mushiyo
 */

#include <iostream>

struct Fraction{
	int numerator;
	int denominator;
};

using namespace std;

int main(){
	int m = 0, n = 0;

    while(cin >> m >> n){
        if(m == 0 && n == 0){
        	break;
        }

        Fraction target;
        target.numerator = m;
        target.denominator = n;

        Fraction left;
        left.numerator = 0;
        left.denominator = 1;

        Fraction current;
        current.numerator = 1;
        current.denominator = 1;

        Fraction right;
        right.numerator = 1;
        right.numerator = 0;

        while(current.numerator != target.numerator && current.denominator != target.numerator){

        }
    }

	return 0;
}
