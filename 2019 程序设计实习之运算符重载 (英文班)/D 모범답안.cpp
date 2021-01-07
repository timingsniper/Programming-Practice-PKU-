#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110;
class CHugeInt {
    // 在此处补充你的代码
private:
    char num_[220];                   // 不需要动态分配内存
public:

    void reverse(char* p)             // 标准字符串原地逆序
    {
        int len = strlen(p);
        int i = 0, j = len - 1;
        while (i <= j)
        {
            swap(p[i], p[j]);
            i++;
            j--;
        }
    }

    CHugeInt(int num)
    {
        memset(num_, 0, sizeof(num_));   // 初始化
        sprintf(num_, "%d", num);        // 将整形直接转化为字符串整数
        reverse(num_);                   // 字符串逆序，为了和习惯相同
    }

    CHugeInt(char* p)
    {
        memset(num_, 0, sizeof(num_));   // 初始化
        strcpy(num_, p);
        reverse(num_);
    }

    CHugeInt operator+(CHugeInt  const& a)  const       // 两个const不是必要的
    {
        CHugeInt temp(0);                                // 这里不能改变第一个数的值，所有返回temp
        int carry = 0;                                   // 进位
        for (int i = 0; i < 210; i++)
        {
            char c1 = num_[i];
            char c2 = a.num_[i];
            if (c1 == 0 && c2 == 0 && carry == 0)
                break;                                    // 到前面0位的情况
            if (c1 == 0)
                c1 = '0';
            if (c2 == 0)
                c2 = '0';

            int k = c1 - '0' + c2 - '0' + carry;
            if (k >= 10)
            {
                carry = 1;
                temp.num_[i] = k - 10 + '0';
            }
            else
            {
                carry = 0;
                temp.num_[i] = k + '0';
            }

        }
        return temp;
    }


    friend ostream& operator<<(ostream& os, const CHugeInt& a)    // 注意必须有const，否则编译不过
    {
        int len = strlen(a.num_);                                   // 倒序输出
        for (int i = len - 1; i >= 0; i--)
        {
            os << a.num_[i];
        }
        return os;
    }

    friend CHugeInt operator+(int num, CHugeInt& a)
    {
        return CHugeInt(num) + a;
    }

    friend CHugeInt operator+(CHugeInt& a, int num)
    {
        return a + CHugeInt(num);
    }

    CHugeInt& operator+=(int num)
    {
        *this = *this + num;       // 自拷贝，没问题
        return *this;
    }

    CHugeInt& operator++()        // 相当于++b
    {
        *this = *this + 1;
        return *this;
    }

    CHugeInt  operator++(int)
    {
        CHugeInt temp(*this);        // 浅拷贝
        *this = *this + 1;
        return temp;                 // 为什么这里temp的值没变？
    }



};
int  main()
{
    char s[210];
    int n;

    while (cin >> s >> n) {
        CHugeInt a(s);
        CHugeInt b(n);
        //cout << a << endl;
        //cout << b << endl;
        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout << ++b << endl;
        cout << b++ << endl;            // 注意b++与++b的区别
        cout << b << endl;
    }
    return 0;
}