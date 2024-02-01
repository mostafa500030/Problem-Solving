#include <iostream>
using namespace std;
const int N = 1e6;
int prime[N + 1];
void sevie()
{
    memset(prime, true, sizeof(prime));
    for (int p = 2;p * p <= N;p++)
    {
        if (prime[p])
        {
            for (int i = p * p;i <= N;i += p)
                prime[i] = 0;
        }
    }
}

int main()
{
    sevie();
    for (int i = 2;i <= N;i++)
        if (prime[i])
            cout << i << endl;
}