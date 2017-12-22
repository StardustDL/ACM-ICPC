/*
[Usaco2007 Jan]Protecting the Flowers 护花
分析：贪心。我们发现，两个相邻的牛（a和b）哪个先走对其它的牛无影响，但是可以通过 a的破坏花×b的时间 和 b的破坏花×a的时间 可以判断哪个先走。
		根据这个排个序 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
int n,tot;
LL ans;
struct data{int t,d;}a[100001];
inline bool cmp(data a,data b){return a.t*b.d<a.d*b.t;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].t,&a[i].d);
        tot+=a[i].d;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        tot-=a[i].d;
        ans+=2*a[i].t*tot;
    }
    printf("%lld",ans);
    return 0;
}

