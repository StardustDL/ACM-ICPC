/*
[Sdoi2016]数字配对
分析：质因数分解，指数和分为奇数偶数两组，二分图，连边，费用为c[i]*c[j]，跑最大费用最大流，费用单调不增，取最后一次费用>=0的时候的流量 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=200+10,MAXE=MAXN*MAXN+10;
typedef long long LL;
const LL INF=100000000000000010LL,MINF=-INF;
struct edge{
	int u,v,nxt;
	LL w,c;
}es[2*MAXE+3];
int last[MAXN+3],q[MAXE+3],tot=1;
LL d[MAXN+3];
int a[MAXN+3],p[MAXN+3],n;
LL b[MAXN+3],c[MAXN+3];
bool inq[MAXN+3];
inline void _addedge(int u,int v,LL w,LL c){
	++tot;
	es[tot].u=u;es[tot].v=v;es[tot].w=w;es[tot].c=c;
	es[tot].nxt=last[u];last[u]=tot;
}
inline void addedge(int u,int v,LL w,LL c){
	_addedge(u,v,w,c);
	_addedge(v,u,-w,0);
}
int S,T,pre[MAXN+3];
bool spfa(){
	int h=0,t=1;
	q[h]=S;memset(inq,0,sizeof(inq));inq[S]=1;memset(pre,0,sizeof(pre));
	for(int i=1;i<=T;i++)d[i]=MINF;
	d[S]=0;//cout<<d[1]<<endl;
	while(h<t){
		int u=q[h];h++;inq[u]=0;//cout<<u<<":"<<endl;
		for(int i=last[u];i;i=es[i].nxt){
			//cout<<es[i].v<<endl;
			if(es[i].c>0 && d[es[i].v]<d[u]+es[i].w){
				d[es[i].v]=d[u]+es[i].w;
				pre[es[i].v]=i;
				//cout<<es[i].v<<" "<<i<<endl;
				if(!inq[es[i].v]){
					inq[es[i].v]=1;
					//cout<<es[i].v<<endl;
					q[t++]=es[i].v; 
				}
			}
		}
	}
	//cout<<"!!"<<endl;
	//for(int i=1;i<=T;i++)cout<<pre[i]<<" ";cout<<endl;
	//cout<<d[T]<<endl;
	return d[T]>MINF;
}
LL C;
LL augment(){
	LL res=INF;
	for(int i=pre[T];i;i=pre[es[i].u]){
		res=min(res,es[i].c);
	}
	//cout<<d[T]<<endl;
	//cout<<res<<endl;
	if(C+res*d[T]<0)res=-C/d[T];//注意这里尽量用完费用 
	C+=res*d[T];
	//if(C<0)return 0;
	for(int i=pre[T];i;i=pre[es[i].u])
		es[i].c-=res,es[i^1].c+=res;
	return res;
}
int getp(int x){
	int ans=0,t=sqrt(x);
	for(int i=2;i<=t;i++){
		while(x%i==0){
			x/=i;
			ans++;
		}
	}
	if(x!=1)ans++;
	return ans;
}
bool isp(int x){
	int t=sqrt(x);
	for(int i=2;i<=t;i++){
		if(x%i==0)return false;
	}
	return true;
}
void build(){
	S=n+1,T=S+1;
	for(int i=1;i<=n;i++){
		p[i]=getp(a[i])&1;
		//cout<<p[i]<<" ";
		if(p[i])addedge(S,i,0,b[i]);
		else addedge(i,T,0,b[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(p[i]!=p[j]){
				if( (a[i]%a[j]==0&&isp(a[i]/a[j])) || (a[j]%a[i]==0)&&isp(a[j]/a[i]) ){
					if(p[i])addedge(i,j,c[i]*c[j],INF);
					else addedge(j,i,c[i]*c[j],INF);
				}
			}
		}
	}
	//for(int i=2;i<=tot;i++)cout<<es[i].u<<" "<<es[i].v<<endl;
}
LL solve(){
	build();C=0;
	LL ans=0;
	while(spfa()){
		LL t=augment();
		//cout<<t<<endl;
		if(t==0)break;
		ans+=t;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	printf("%lld\n",solve()); 
	return 0;
}

