#include<bits/stdc++.h>
using namespace std;

int const N=1e5+5, M=1e5+5, OO = 0x3f3f3f3f, MOD=1e9+7;

#define cost first
#define from second.first
#define to  second.second


int n,m,c,u,v;
pair<int,pair<int,int>> edges[M];
int par[N];

int findParent(int u)
{
    if(par[u]==u)
        return u;
    return par[u]=findParent(par[u]);

}

void join(int a, int b)
{
    a=findParent(a);
    b=findParent(b);
    if(a!=b)
        par[b]=a;
}

int main()
{

}
