/*
Rmq Problem
分析：可以先暴力求出所有mex[1..i]，然后注意mex是单调增的，
		维护当前左端点为l的mex数组。 
		离线询问，按左端点排序，当左端点=当前左端点的时候直接输出
		如果不等于，那么我们记录当前数下一个出现位置next[i]
		那么[i+1..next[i]-1]这些位置的mex值只要大于a[i]的，就会变成了a[i]，因为mex是单调的，所以从next[i]-1到i+1来更新，一旦不能更新就break 
	  正确复杂度的算法：线段树修改
	  或者莫队+权值分块：对于每次查询的区间[l,r]，将权值分块，维护每一块内数字的出现次数，和每个权值的出现次数。因为mex值不会超过区间长度，这样我们就可以在O(√n)的时间内得到一个没有全被覆盖的区间，然后再O(√n)的时间暴力枚举当前块内的每个数，看是否出现过，即可得到答案。我们发现统计的信息可以在O(1)的时间内转移，于是用莫队算法来支持多次询问。 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=200000;
typedef int arr[MAXN+3];
arr a,v,last,mex,next,ans;
int n,q;
struct query{int l,r,id;}qs[MAXN+3];
bool cmp(query x,query y){return x.l<y.l;}
void change(int x){
	int ed=next[x]?next[x]:(n+1);
    mex[x]=0;
    for(int i=ed-1;i>x;i--){//这里倒着更新， 降低复杂度 
        if(mex[i]<=a[x])break;
        mex[i]=a[x];
    }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int cur=0,i=1;i<=n;i++){
    	v[a[i]]=1;
        while(v[cur]!=0)cur++;
        mex[i]=cur;
    }
    for(int i=1;i<=n;i++){
        next[last[a[i]]]=i;
        next[i]=n+1;
        last[a[i]]=i;
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&qs[i].l,&qs[i].r);
        qs[i].id=i;
    }
    sort(qs+1,qs+1+q,cmp);
    int curl=1;
    for(int i=1;i<=q;i++){
    	for(int j=curl;j<qs[i].l;j++)change(j);
        ans[qs[i].id]=mex[qs[i].r];
        curl=qs[i].l;
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}
