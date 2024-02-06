//soluation for problem in https://codeforces.com/contest/6/problem/C

#include <iostream>
typedef long long ll;
#define tt cin >>t;\
while(t--)
using namespace std;
const long long mod = 1e9 + 7;
void f()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	f();
	int n, arr[100005], co1 = 0, co2 = 0, c1 = 0, c2 = 0;
	cin >> n;
	int  s = 0, e = n - 1;
	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	while (true)
	{
		if (co1 > co2)
		{
			co2 += arr[e];
			e--;
			c2++;
		}
		else if (co1 == co2 && co1 == 0 && n != 1)
		{
			co1 += arr[s];co2 += arr[e];
			s++;e--;
			c1++;c2++;
		}
		else if (co1 == co2 && co1 == 0 && n == 1)
		{
			c1 = 1;
			break;
		}
		else if (co1 == co2 && s == e)
		{
			co1 += arr[s];
			s++;
			c1++;
		}
		else
		{
			co1 += arr[s];
			s++;
			c1++;
		}
		if ((n--) == 2)
		{
			break;
		}
	}
	cout << c1 << " " << c2;
}