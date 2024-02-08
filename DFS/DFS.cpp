#include <iostream>
#include <map>
#include<algorithm>
#include<deque>
#include<math.h>
using namespace std;
deque<deque<int>>d;
bool vis[5005];
//deque<bool>found(5005);
int co = 0;
void dfs(int i)
{
	co++;
	vis[i] = 1;
	for (auto v : d[i])
		if (!vis[v])
			dfs(v);
}
int main()
{
	map<string, int>an;
	int n, m;
	string u, v;
	while (cin >> n >> m && n || m)
	{
		int ma = 0;
		an.clear();
		d.clear();
		for (int i = 0;i < n;i++)
		{
			cin >> u;
			an[u] = i;
			vis[an[u]] = 0;
		}
		d.resize(n);
		for (int i = 0;i < m;i++)
		{
			cin >> u >> v;
			d[an[u]].push_back(an[v]);
			d[an[v]].push_back(an[u]);
			//found[an[u]] = found[an[v]] = 1;
		}
		for (int i = 0;i < n;i++)
		{
			co = 0;
			//for (int j = 0;j < n;j++)vis[j] = 0;
			if (!vis[i])
			{
				dfs(i);
				//cout << co << " ";
			}
			if (ma < co)ma = co;
		}
		cout << ma<<endl;
	}
}