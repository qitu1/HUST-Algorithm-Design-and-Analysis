#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#define inf 2147483640
#define LL long long
#define free(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);
using namespace std;
inline LL getint() {
    LL x=0,f=1;char ch=getchar();
    while (ch>'9' || ch<'0') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
 
const int maxn=1000010;
struct point {double x,y;int flag;}p[maxn];
int n,tmp[maxn];
 
bool cmpx(point a,point b) {
    return a.x==b.x ? a.y<b.y : a.x<b.x;
}
bool cmpy(int a,int b) {
    return p[a].y==p[b].y ? p[a].x<p[b].x : p[a].y<p[b].y;
}
double dis(point a,point b) {
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double solve(int l,int r) {
    double res=1e60;
    if (l==r) return res;
    if (l+1==r) {
        if (p[l].flag==p[r].flag) return res;
        return dis(p[l],p[r]);
    }
    int mid=(l+r)>>1;
    res=solve(l,mid);
    res=min(res,solve(mid+1,r));
    int num=0;
    for (int i=l;i<=r;i++)
        if (fabs(p[i].x-p[mid].x)<=res) tmp[++num]=i;
    sort(tmp+1,tmp+num+1,cmpy);
    for (int i=1;i<=num;i++)
        for (int j=i+1;j<=num;j++) {
            if (fabs(p[tmp[i]].y-p[tmp[j]].y)>=res) break; //ºÙ÷¶
            if (p[tmp[i]].flag!=p[tmp[j]].flag) res=min(res,dis(p[tmp[i]],p[tmp[j]]));
        }
    return res;
}
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y),p[i].flag=0;
        for (int i=1;i<=n;i++) scanf("%lf%lf",&p[i+n].x,&p[i+n].y),p[i+n].flag=1;
        n<<=1;
        sort(p+1,p+1+n,cmpx);
        printf("%.3f\n",solve(1,n));
    }
    return 0;
}
