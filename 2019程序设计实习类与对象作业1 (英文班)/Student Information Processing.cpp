// ConsoleApplication.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
	// Your Code Here
private:
	char name[100], c1, c2, c3, c4, c5;
	int age, id, scores[4];
	float ans;

public:
	void calculate() {
		int a = 0;
		for (int i = 0; i < 4; i++) {
			a += scores[i];
		}
		ans = a / 4.0;
	}
	void input() {
		cin.getline(name, 100, ',');
		cin >> age >> c1 >> id >> c2 >> scores[0] >> c3 >> scores[1] >> c4 >> scores[2] >> c5 >> scores[3];
	}
	void output() {
		cout << name << "," << age << "," << id << "," << ans;
	}
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}