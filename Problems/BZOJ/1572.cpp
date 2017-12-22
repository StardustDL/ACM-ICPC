/*
[Usaco2009 Open]��������Job
������̰�ģ�������ʱ���С����ÿ��push��ȥ�����������������>��ǰʱ�䣬��ôpop����С�ġ��������queue��ʣ�µ����ĺ;��Ǵ� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
struct data{
	int p,d;
	bool operator <(const data &t)const{
		return p>t.p;
	}
}ds[MAXN+3];
bool cmp(data a,data b){
	return a.d<b.d;
}
priority_queue<data> q;
long long ans=0;
int rest=0,n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&ds[i].d,&ds[i].p);
	sort(ds+1,ds+n+1,cmp);
	for(int i=1;i<=n;i++){
		q.push(ds[i]);rest++;ans+=ds[i].p;
		if(rest>ds[i].d){
			rest--;
			ans-=q.top().p;q.pop();
		}
	}
	printf("%lld\n",ans);
	return 0;
}

