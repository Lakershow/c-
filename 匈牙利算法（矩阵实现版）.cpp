#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;

class matrix
{
public:
    matrix(int x,int y)
    {
        row=x;
        col=y;
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                grad[i][j]=0;
            }
        }
    }
    void add(int a,int b)
    {
        grad[a][b]=1;
    }
    int hgr()
    {
        int res=0;
        memset(match,0,sizeof match);
        for(int i=1;i<=row;i++)
        {
            memset(st, 0, sizeof st);
            if(find(i))res++;
        }
        return res;
    }
    bool find(int x)
    {
        for(int i=1;i<=col;i++)
        {
            if(grad[x][i]&&!st[i])
            {
                st[i]=true;
                if(match[i]==0||find(match[i]))
                {
                    match[i]=x;
                    return true;
                }
            }
        }
        return false;
    }
private:
    int grad[N][N];
    int match[N];
    bool st[N];
    int row,col;
};

int main()
{
    int n1,n2,m;
    cin>>n1>>n2>>m;
    matrix ma(n1,n2);
    while (m -- )
    {
        int a,b;
        cin>>a>>b;
        ma.add(a,b);
    }
    cout<<ma.hgr();
}
