/*
����
���������ȶ�������⣬���˷�Χ֮�󣬶�ά�����ݽṹ����Ȼ���ܹ��ģ��������ǿ��ܻῼ�ǰ�һά����֮����һλ�����ݽṹʲô�ģ�Ȼ��cdq����ȴ�ܹ��ܺõ������������á�
		���ȣ�����ÿһ��ѯ����ͣ���Ȼ��x������ߵĲ��ҳ���ʱ������֮ǰ�����е�change�������ܻ���Ӱ�졣
		���ǰ���x��һ�ؼ���,y�ڶ��ؼ���,���������ؼ������������е�ѯ�ʣ�Ȼ����cdq��ʱ��ÿ�εݹ鴦��������䣬����x��̬�Ľ�y��һ�е�ֵ�ӵ���״������������Ұ�ߵ�����ѯ�ʣ�ע���������״��������Ҫ��ģ�Ҳ����ÿ��cdq���ǲ��ò�ͬ����״���顣 
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

