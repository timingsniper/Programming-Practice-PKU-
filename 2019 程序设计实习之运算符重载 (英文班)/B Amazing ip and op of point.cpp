// ConsoleApplication.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point() { };
	// Your Code Here

	//input overload
	friend istream& operator >>(istream &input, Point &a) {
		input >> a.x >> a.y;
		return input;
	}

	//cout overload
	friend ostream& operator<<(ostream& output, Point& b) {
		output << b.x << "," << b.y;
		return output;
	}

};
int main()
{
	Point p;
	while (cin >> p) {
		cout << p << endl;
	}
	return 0;
}