/*Filename: struct.cpp
 *Author: Mushiyo
 *Usage: Demostrate how to manipulate the struct data type
 */

#include <iostream>

using namespace std;

struct Point{
	int x;
	int y;
};

int main(){

	Point p1 = {3, 4};
	Point p2;
	p2.x = p1.y;
	p2.y = p1.x;

	cout << "The coordinate of point 1 is " << "(" << p1.x << ", " << p1.y << ")." << endl;
	cout << "The coordinate of point 2 is " << "(" << p2.x << ", " << p2.y << ")." << endl;

	return 0;
}
