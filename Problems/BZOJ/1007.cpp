/*
1007: [HNOI2008]水平可见直线
分析：按斜率从小到大排序，枚举直线，比较cur与cur-1的交点的横坐标是否在cur-1与cur-2的交点横坐标之下，维护一个单调栈 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=50000;
struct line{int k,b,id;}a[MAXN+3],aa[MAXN+3];
double cross(line &c,line &d){
    return (d.b-c.b+0.0)/(c.k-d.k+0.0);
}
int n,s[MAXN+3],top,M;double x1,x2;
bool cmp1(line a,line b){return a.k>b.k;}
bool cmp2(int c,int d){return a[c].id<a[d].id;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&aa[i].k,&aa[i].b),aa[i].id=i;
    sort(aa+1,aa+n+1,cmp1);
    for(int i=1;i<=n;i++) 
        if(aa[i].k!=a[i-1].k)a[++M]=aa[i];
        else if(aa[i].b>a[M].b)a[M].b=aa[i].b,a[M].id=aa[i].id;
    s[1]=1;top=1;
    for(int i=2;i<=M;i++){
        while(top>=2){
            x1=cross(a[s[top-1]],a[i]);
            x2=cross(a[s[top]],a[i]);
            if (x1<=x2+1e-6) top--;else break;
        }
        s[++top]=i;
    }
    sort(s+1,s+top+1,cmp2);
    for(int i=1;i<=top;i++)printf("%d ",a[s[i]].id);
    return 0;
}
