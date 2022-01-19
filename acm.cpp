#include<iostream>
using namespace std;
const int N=1e3+5;

int n,m;
char g[N][N];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int dfs(int x,int y,int d)
{
    if(x<1||x>n||y<1||y>m)
        return 0;
    if(g[x][y]=='/')
        d^=1;
    else
        d^=3;
    return dfs(x+dx[d],y+dy[d],d)+1;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%s",g[i]+1);
    int res=0;
    for(int i=1;i<=n;++i)
    {
        res=max(res,dfs(i,1,1));
        res=max(res,dfs(i,m,3));
    }
    for(int i=1;i<=m;++i)
    {
        res=max(res,dfs(1,i,2));
        res=max(res,dfs(n,i,0));
    }
    printf("%d\n",res);
    return 0;
}