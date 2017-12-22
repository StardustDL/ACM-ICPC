/*
Pollution
题意：一张无向图，一些点上有值，每单位时间内，一个点会向其相邻的点平均分配其值（w[i]/d[i]），问当所有点的值不再改变时，每个点的值是多少 
分析：可以将题目中的“不再变化”理解成平衡（入=出），易知平衡时每个点的值=所在联通块总值*（当前节点的度数/联通块中总度数），这里的总度数指块中各个点出入度之和 
	  维护联通块使用并查集即可，注意孤点的情况 
*/ 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
int n,m,pa[MAXN+3],d[MAXN+3],cnt[MAXN+3];
double w[MAXN+3],sum[MAXN+3];
int find(int x){
	return pa[x]==x?x:pa[x]=find(pa[x]); 
}
void merge(int a,int b){
	d[a]++;d[b]++;//两点度数分别+1 
	a=find(a),b=find(b);
	if(a==b) cnt[a]+=2;
	else{
		pa[a]=b;
		sum[b]+=sum[a];
		cnt[b]+=cnt[a]+2;//总度数+2 
	}
}
void input(){
	memset(w,0,sizeof(w));
	memset(sum,0,sizeof(sum));
	memset(d,0,sizeof(d));
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=n;i++){
		scanf("%lf",&w[i]);
		sum[i]=w[i];cnt[i]=0;pa[i]=i;
	}
	while(m--){
		scanf("%d %d",&x,&y);
		merge(x,y);
	}
}
double get(int x){
	if(!d[x])return sum[x];//孤点 
	return d[x]*sum[find(x)]/cnt[find(x)];
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		input();
		for(int i=1;i<=n;i++)printf("%.3lf\n",get(i));
		puts("");
	}
	return 0;
}

