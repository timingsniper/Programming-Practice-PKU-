// ConsoleApplication.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Complex {
private:
    double r, i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }

    Complex& operator=(const string& a) {
        this->r = 0; this->i = 0;
        bool plusReached = false;

        for (int count = 0; count < a.length(); count++) {
            if (a[count] == '+') {
                plusReached = true;
                continue;
            }
            else if (a[count] >= '0' && a[count] <= '9') {
                if (plusReached) {
                    this->i = i * 10 + a[count] - '0'; //converting string value num into int
                }
                else if (!plusReached) {
                    this->r = r * 10 + a[count] - '0';
                }
            }
        }
        return *this;
   }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}