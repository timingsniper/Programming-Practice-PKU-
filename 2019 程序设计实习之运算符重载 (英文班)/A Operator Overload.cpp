// ConsoleApplication.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class MyInt
{
	int nVal;
public:
	MyInt(int n) { nVal = n; }
	// Your Code Here

	//override int format
	operator int() {
		return nVal;
	}

	//override -
	MyInt& operator -(int a) {
		nVal = nVal - a;
		return *this;
	}
};
int Inc(int n) {
	return n + 1;
}
int main() {
	int n;
	while (cin >> n) { //20
		MyInt objInt(n); //20
		objInt - 2 - 1 - 3;
		cout << Inc(objInt);
		cout << ",";
		objInt - 2 - 1;
		cout << Inc(objInt) << endl;
	}
	return 0;
}