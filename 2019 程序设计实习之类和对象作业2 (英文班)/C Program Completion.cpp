// ConsoleApplication.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class A {
public:
	int val;

	// Your Code Here
	A(int a = 123) {
		val = a;
	}

		
	A& GetObj() {
		return *this;
	}
};
int main()
{
	int m, n;
	A a;
	cout << a.val << endl; //123
	while (cin >> m >> n) {
		a.GetObj() = m; // object = int, constructor is called
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val << endl;
	}
	return 0;
}