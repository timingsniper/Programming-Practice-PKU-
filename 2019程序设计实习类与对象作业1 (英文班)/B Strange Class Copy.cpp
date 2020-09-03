// ConsoleApplication.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;
class Sample {
public:
	int v;
	// Your Code Here
	Sample(int a) {
		v = a;
	}
	Sample(Sample const &a) { //copy constructor 
		v = a.v+2;
	}
	Sample() {
	}
		

};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{

	//when sample is called again in printanddouble, copy constructor is called one more time

	Sample a(5); // a = 5
	Sample b = a; //b = 7

	//cout << b.v;

	PrintAndDouble(b); //9
	Sample c = 20; //c = 20

	//cout << c.v;

	PrintAndDouble(c); //22
	Sample d; //d = 5
	d = a;
	cout << d.v; //5
	return 0;
}