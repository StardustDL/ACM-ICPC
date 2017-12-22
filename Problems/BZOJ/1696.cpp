/*
[Usaco2007 Feb]Building A New Barn��ţ��
��������min( sum{|x-xi|} + sum{|y-yi|} )����x,y����λ����ע��û����ͷţ�ĳԲ�λ�������ڵ�
	  ����������ֻ��һ����λ������ô������1��n����x����λ����y����λ����������������ĵ㡣������Ҫע�⣬����㲻�ܺ�ţ�غϡ�����غϣ���ô��ȡţ�����������ĸ��㣬����û����ͷţ�ĳԲ�λ�������ڵġ�������֤���������š�
	  ����ż������2����λ��������ô���Ǿ�Ҫ����������λ�������еĿ��е㡣����ʵ�����Χ�����еĵ㶼�ǿ��е㣬������(xx-x+1)*(yy-y+1)����������ע�⣬�����治����ţ������ÿ�ҵ�һ��ţ����Ҫ��ȥһ���𰸡�
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
struct data{ int x, y; }a[MAXN+3];
bool cmpx(const data &a, const data &b) { return a.x<b.x; }
bool cmpy(const data &a, const data &b) { return a.y<b.y; }
int n, ans1, ans2;
bool check(int x, int y) {
    for(int i=1;i<=n;i++)if(a[i].x==x && a[i].y==y) return 0;
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
    if(n&1) {
        int x,y;
        sort(a+1,a+1+n, cmpx);x=a[(n>>1)+1].x;
        sort(a+1, a+1+n, cmpy);y=a[(n>>1)+1].y;
        if(check(x,y)){
            for(int i=1;i<=n;i++)ans1+=abs(x-a[i].x)+abs(y-a[i].y);
            ans2=1;
        }
        else {
            int tp[4],fx[]={x+1, x-1, x, x}, fy[]={y, y, y-1, y+1};ans1=INF;
            memset(tp,0,sizeof(tp));
            for(int i=1;i<=n;i++)for(int j=0;j<4;j++)tp[j]+=abs(fx[j]-a[i].x)+abs(fy[j]-a[i].y);
            for(int j=0;j<4;j++)if(ans1>tp[j])ans1=tp[j],ans2=1;else if(ans1==tp[j])++ans2;
        }
    }
    else {
        int x, y, xx, yy;
        sort(a+1,a+1+n,cmpx);x=a[(n>>1)].x;xx=a[(n>>1)+1].x;
        sort(a+1,a+1+n,cmpy);y=a[(n>>1)].y;yy=a[(n>>1)+1].y;
        ans2=(xx-x+1)*(yy-y+1);
        for(int i=1;i<=n;i++){
            if(a[i].x>=x&&a[i].x<=xx&&a[i].y>=y&&a[i].y<=yy)--ans2;
            ans1+=abs(x-a[i].x)+abs(y-a[i].y);
        }
    }
    printf("%d %d",ans1,ans2);
    return 0;
}
