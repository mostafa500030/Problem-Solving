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



int kruskal()
{
    int ret=0;
    iota(par,par+n+1,0);
    sort(edges,edges+m);
    for(int i=0; i<m; i++)
    {
        if(findParent(edges[i].to)!=findParent(edges[i].from))
        {
            join(edges[i].from,edges[i].to);
            ret+=edges[i].cost;
        }
    }
    return ret;
}


int main()
{
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        cin>>u>>v>>c;
        scanf("%d %d %d",&u,&v,&c);
        edges[i]={c,{u,v}};
    }
    cout<<kruskal();

    return 0;
}