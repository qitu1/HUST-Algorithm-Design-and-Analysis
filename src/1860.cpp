#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<map>
using namespace std;

const int maxn = 200 + 5;

int n, m, s;   //货币总数、兑换点数量、有第s种货币
double v;     //持有的s货币本金
int cnt;

double d[maxn];

struct node
{
    int a;
    int b;
    double rate;
    double c;
}edge[maxn];

bool bellman_ford()
{
    memset(d, 0, sizeof(d));
    d[s] = v;

    bool flag;
    for (int i = 1; i <= n - 1; i++)
    {
        flag = false;
        for (int j = 0; j < cnt; j++)
        {
            if (d[edge[j].b] < (d[edge[j].a] - edge[j].c)*edge[j].rate)
            {
                d[edge[j].b] = (d[edge[j].a] - edge[j].c)*edge[j].rate;
                flag = true;
            }
        }
        if (!flag)  break;
    }

    for (int j = 0; j < cnt;j++)
    if (d[edge[j].b] < (d[edge[j].a] - edge[j].c)*edge[j].rate)
        return true;
    return false;
}

int main()
{
    //freopen("D:\\txt.txt", "r", stdin);
    int a, b;
    double    rab, cab, rba, cba;
    while (~scanf("%d%d%d%lf", &n, &m, &s, &v))
    {
        cnt = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%lf%lf%lf%lf", &a, &b, &rab, &cab, &rba, &cba);
            edge[cnt].a = a;
            edge[cnt].b = b;
            edge[cnt].rate = rab;
            edge[cnt++].c = cab;
            edge[cnt].a = b;
            edge[cnt].b = a;
            edge[cnt].rate = rba;
            edge[cnt++].c = cba;
        }
        if (bellman_ford())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
