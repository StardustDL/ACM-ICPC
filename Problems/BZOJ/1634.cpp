/*
[Usaco2007 Jan]Protecting the Flowers ����
������̰�ġ����Ƿ��֣��������ڵ�ţ��a��b���ĸ����߶�������ţ��Ӱ�죬���ǿ���ͨ�� a���ƻ�����b��ʱ�� �� b���ƻ�����a��ʱ�� �����ж��ĸ����ߡ�
		��������Ÿ��� 
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

