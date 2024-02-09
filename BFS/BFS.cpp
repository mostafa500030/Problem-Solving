// the solutionof problem https://codeforces.com/problemset/problem/242/C

#include <iostream>
#include <iostream>
#include <map>
#include<algorithm>
#include<deque>
#include<math.h>
#include<queue>
using namespace std;
map<pair<int, int>,int>graph, vis;
int xx[] = { 1,1,1,-1,-1,-1,0,0 };
int yy[] = { 1,-1,0,1,-1,0,1,-1 };
void bfs(int x, int y)
{
	queue<pair<int,int>>q;
	q.push({ x,y });
	vis[{x, y}] = 0;
	while (!q.empty())
	{
		int f = q.front().first,s=q.front().second;
		//cout << f << " " << s << " " << vis[{f, s}];
		q.pop();
			for (int i = 0;i < 8;i++)
			{
				if (vis[{f + xx[i], s + yy[i]}] > vis[{f,s}]+1 && graph[{f + xx[i], s + yy[i]}])
				{
					vis[{f + xx[i], s + yy[i]}] = vis[{f, s}] + 1;
					q.push({ f + xx[i], s + yy[i] });
				}
			}
	}
}
int main()
{
	int x0, y0, x1, y1,n,r,ry1,ry2;
	cin >> x0 >> y0 >> x1 >> y1>>n;
	for (int i = 0;i < n;i++)
	{
		cin >> r >> ry1 >> ry2;
		for (int i = ry1;i <= ry2;i++)
		{
			graph[{r, i}] = 1;vis[{r, i}] = 1e9+5;
		}
	}
	bfs(x0,y0);
	if (vis[{x1, y1}] == 1e9+5)cout << -1;else cout << vis[{x1, y1}];
}