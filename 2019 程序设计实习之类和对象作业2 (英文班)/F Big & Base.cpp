// ConsoleApplication.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Base {
public:
	int k;
	Base(int n) :k(n) { }
};
class Big
{
public:
	int v;
	Base b;
	// Your Code Here

	Big(int n) : v(n), b(n) {};



};
int main()
{
	int n;
	while (cin >> n) { //3
		Big a1(n); //a1 = 3
		Big a2 = a1; //a2 = 3
		cout << a1.v << "," << a1.b.k << endl;
		cout << a2.v << "," << a2.b.k << endl;
	}
}