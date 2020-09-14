// ConsoleApplication.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class MyString {
	char* p;
public:
	MyString(const char* s) {
		if (s) {
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else
			p = NULL;

	}
	~MyString() { if (p) delete[] p; }
	// Your Code Here
	friend ostream& operator<<(ostream& output, MyString& a) {
		output << a.p;
		return output;
	}

	void Copy(char* tt) {
		p = new char[strlen(tt) + 1];
		strcpy(p, tt);
	}

	MyString& operator =(MyString& a) {
		p = new char[strlen(a.p) + 1];
		strcpy(p, a.p);
		return *this;
	}

	MyString& operator =(char *a) {
		p = new char[strlen(a) + 1];
		strcpy(p, a);
		return *this;
	}



};
int main()
{
	char w1[200], w2[100];
	while (cin >> w1 >> w2) {
		MyString s1(w1), s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;

	}
}