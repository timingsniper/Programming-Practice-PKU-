// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Array2 {
    // Your Code Here
private:
    int x, y;
    int* arr;

public:
    Array2() { arr = NULL; }
    Array2(int x_, int y_) : x(x_), y(y_) {
        arr = new int[x * y];
    }

    Array2(Array2& arr_) {
        arr = new int[arr_.x * arr_.y];
        x = arr_.x; y = arr_.y;
        memcpy(arr, arr_.arr, sizeof(int) * x * y);
    }

    int* operator[](int a_) {
        return arr + a_ * y;
    }

    int operator()(int a, int b) {
        return arr[a * y + b];
    }
};

int main() {
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

/*
Regarding overloading [] :
此处的重载似乎不能计算出值？
其实这儿我们可以理解为二维数组中，我们只在计算行数的第一个[]处引起了重载，
而第二个[]处没有用到重载，因为一个二维数组，p[i][j]中，p[i]本身就是一个指针，
那么结合本题，可知在进行一次重载后返回的地址应该就是num[t] = num + i * col,
那么当我们再次求值时，首地址就相当于锁定在num[i][j]所在的行数的第一列。*/