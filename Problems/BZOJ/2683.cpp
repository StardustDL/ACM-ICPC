/*
简单题
分析：首先对于这道题，看了范围之后，二维的数据结构是显然不能过的，于是我们可能会考虑把一维排序之后另一位上数据结构什么的，然而cdq分治却能够很好的体现它的作用。
		首先，对于每一个询问求和，显然是x在它左边的并且出现时间在它之前的所有的change对他可能会有影响。
		我们按照x第一关键字,y第二关键字,操作第三关键字来排序所有的询问，然后在cdq的时候，每次递归处理左半区间，按照x动态的将y这一列的值加到树状数组里，来更新右半边的所有询问，注意这里的树状数组是需要清的，也就是每次cdq都是采用不同的树状数组。 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=500000,MAXQ=200000;
struct data{
	int opt,x,y,belong,no,A;
	bool operator <(const data &t)const{
		if(x==t.x&&y==t.y)return opt<t.opt;
		else if(x==t.x)return y<t.y;
		else return x<t.x;
	}
}q[MAXQ*4+3],tq[MAXQ*4+3];
int n,ans[MAXQ+3];
int c[MAXN+3];
#define lowbit(x) (x&-x)
void update(int x,int ad){
	for(int i=x;i<=n;i+=lowbit(i))c[i]+=ad;
}
int sum(int x){
	int ans=0;
	for(int i=x;i;i-=lowbit(i))ans+=c[i];
	return ans;
}
void solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1,l1=l,l2=mid+1;
	for(int i=l;i<=r;i++){
		if(q[i].no<=mid && q[i].opt==1)update(q[i].y,q[i].A);
		if(q[i].no>mid && q[i].opt==2)ans[q[i].belong]+=q[i].A*sum(q[i].y);
	}
	for(int i=l;i<=r;i++){
		if(q[i].no<=mid && q[i].opt==1)update(q[i].y,-q[i].A);
	}
	for(int i=l;i<=r;i++){if(q[i].no<=mid)tq[l1++]=q[i];else tq[l2++]=q[i];}
	for(int i=l;i<=r;i++)q[i]=tq[i]; 
	solve(l,mid);solve(mid+1,r);
}
int T,cnt;
int main(){
	scanf("%d",&n);
	int opt,x,y,x2,y2,A;
	while(scanf("%d",&opt) && opt!=3){
		if(opt==1){
			scanf("%d%d%d",&x,&y,&A);
			q[++cnt].opt=opt;q[cnt].A=A;q[cnt].x=x;q[cnt].y=y;q[cnt].belong=0;q[cnt].no=cnt; 
		}
		else{
			scanf("%d%d%d%d",&x,&y,&x2,&y2);
			q[++cnt].opt=opt;q[cnt].A=1;q[cnt].x=x-1;q[cnt].y=y-1;q[cnt].belong=++T;q[cnt].no=cnt;
			q[++cnt].opt=opt;q[cnt].A=-1;q[cnt].x=x-1;q[cnt].y=y2;q[cnt].belong=T;q[cnt].no=cnt;
			q[++cnt].opt=opt;q[cnt].A=-1;q[cnt].x=x2;q[cnt].y=y-1;q[cnt].belong=T;q[cnt].no=cnt;
			q[++cnt].opt=opt;q[cnt].A=1;q[cnt].x=x2;q[cnt].y=y2;q[cnt].belong=T;q[cnt].no=cnt;
		}
	}
	sort(q+1,q+cnt+1);
	solve(1,cnt);
	for(int i=1;i<=T;i++){
		printf("%d\n",ans[i]);
	} 
	return 0;
}

