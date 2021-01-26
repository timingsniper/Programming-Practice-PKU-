#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;

using namespace std;
const int MAX = 110;
class CHugeInt {
	// Your Code Here
private:
	char num[220];

public:
	void reverse(char* p) {
		int len = strlen(p);
		int i = 0, j = len - 1;

		while (i <= j) {
			swap(p[i], p[j]);
			i++;
			j--;
		}
	}

	CHugeInt(int a) {
		memset(num, 0, sizeof(num));
		sprintf(num, "%d", a);
		reverse(num);
	}

	CHugeInt(char* a) {
		memset(num, 0, sizeof(num));
		strcpy(num, a);
		reverse(num);
	}

	CHugeInt operator+(CHugeInt const& a) const{
		CHugeInt temp(0);
		int carry = 0;
		for (int i = 0; i < 210; i++) {
			char c1 = num[i];
			char c2 = a.num[i];

			if (c1 == 0 && c2 == 0 && carry == 0) {
				break;
			}
			if (c1 == 0)
				c1 = '0';
			if (c2 == 0)
				c2 = '0';

			int k = c1 - '0' + c2 - '0' + carry;

			if (k >= 10) {
				carry = 1;
				temp.num[i] = k - 10 + '0';
			}
			else {
				carry = 0;
				temp.num[i] = k + '0';
			}
		}
		return temp;
	}

	friend ostream& operator<<(ostream& os, const CHugeInt& a) {
		int len = strlen(a.num);
		for (int i = len - 1; i >= 0; i--) {
			os << a.num[i];
		}
		return os;
	}

	friend CHugeInt operator+(CHugeInt& a, int number) {
		return a + CHugeInt(number);
	}

	friend CHugeInt operator+(int number, CHugeInt& a) {
		return CHugeInt(number) + a;
	}

	CHugeInt& operator+=(int number) {
		*this = *this + number;
		return *this;
	}

	CHugeInt operator++(int) { //b++
		CHugeInt temp(*this);
		*this = *this + 1;
		return temp;
	}

	CHugeInt operator++() {
		*this = *this + 1;
		return *this;
	}


};

int  main()
{
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout << ++b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}