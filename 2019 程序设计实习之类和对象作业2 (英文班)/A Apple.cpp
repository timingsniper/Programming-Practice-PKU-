// ConsoleApplication.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;
class Apple {
	// Your Code Here
public:
	static int nTotalNumber;
	Apple() {
		nTotalNumber++;
	}
	~Apple() {
		nTotalNumber--;
	}


	static void PrintTotal() {
		cout << nTotalNumber << endl;
	}

};
int Apple::nTotalNumber = 0;
Apple Fun(const Apple& a) {
	a.PrintTotal();
	return a;
}
int main()
{
	//分析main执行的过程：
	//1.无参构造函数生成4个对象，进入Fun，输出nTotalNumber = 4
	//2.退出Fun，复制构造函数生成1个对象并返回到main中成为临时对象，语句执行完成，临时对象析构
	//3.无参构造函数生成2个对象，输出nTotalNumber = 5
	//4.析构new出来的4个对象，输出nTotalNumber = 1
	Apple* p = new Apple[4]; //creates 4 new apples
	Fun(p[2]); //4
	//Apple::PrintTotal();
	Apple p1, p2;
	Apple::PrintTotal(); //5
	delete[] p;
	p1.PrintTotal(); //1
	return 0;
}