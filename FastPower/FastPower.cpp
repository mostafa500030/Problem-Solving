#include <iostream>

using namespace std;

long long mod = 1e9 + 7;

long long FastPower(long long b, long long p, long long m)
{
	if (p == 0)return 1;
	if (p == 1)return b;
	long long halfpower = FastPower(b, p / 2, m);
	long long ret = (halfpower * halfpower) % m;
	if (p % 2)
		ret = (ret * b) % m;
	return ret % m;
}

int main()
{
	cout << FastPower(2, 1e8, mod) << endl;
}
