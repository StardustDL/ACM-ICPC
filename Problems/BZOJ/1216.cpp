/*
[HNOI2003]操作系统
分析：用堆模拟一下 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue> 
using namespace std;
const int MAXN=300000,INF=0x3f3f3f3f; 
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int t1[MAXN+3],t2[MAXN+3],rk[MAXN+3],st[MAXN+3],ed[MAXN+3],x,now;
struct data{int id,t;};
struct res{int id,t;}ans[MAXN+3];
priority_queue<data>q;
bool operator<(data a,data b){
	return rk[a.id]<rk[b.id] || rk[a.id]==rk[b.id] && t1[a.id]>t1[b.id];
}
bool operator<(res a,res b){return a.t<b.t;}
int main(){
	while(scanf("%d",&x)!=EOF){
		t1[x]=read();t2[x]=read();rk[x]=read();
		ans[x].id=x;
	}
	t1[x+1]=INF;
	for(int i=1;i<=x+1;i++){
		int t=t1[i]-now;
		while(!q.empty()&&q.top().t<=t){
			now+=q.top().t;t-=q.top().t;
			ans[q.top().id].t=now;q.pop();
		}
		if(i==x+1)break;
		if(!q.empty()&&t){
			data x=q.top();q.pop();
			x.t-=t;
			q.push(x);
		}
		now=t1[i];
		q.push((data){i,t2[i]});
	}
	sort(ans,ans+x+1);
	for(int i=1;i<=x;i++)
		printf("%d %d\n",ans[i].id,ans[i].t);
	return 0;
}
