/*
[Noi2015]程序自动分析
分析：并查集+离散化 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=100010,INF=0x3f3f3f3f;
struct data{
	int i,j,e;
}ds[MAXN+3];
int t,n,pa[2*MAXN+3],mxi,us[2*MAXN+3],cnt,id[2*MAXN+3];
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
void input(){
	scanf("%d",&n);
	mxi=0;cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&ds[i].i,&ds[i].j,&ds[i].e);
		us[++cnt]=ds[i].i;
		us[++cnt]=ds[i].j;
	}
	sort(us+1,us+cnt+1);
	int len=unique(us+1,us+cnt+1)-us-1;
	for(int i=1;i<=n;i++){
		ds[i].i=lower_bound(us+1,us+len+1,ds[i].i)-us;
		ds[i].j=lower_bound(us+1,us+len+1,ds[i].j)-us;
	}
	memset(pa,0,sizeof(int)*(len+5));
}
int main(){
	int i,j,k;
	for(scanf("%d",&t);t;t--){
		input();
		for(i=1;i<=n;i++){
			if(ds[i].e==0)continue;
			j=find(ds[i].i);k=find(ds[i].j);
			if(j!=k)pa[j]=k;
		}
		for(i=1;i<=n;i++){
			if(ds[i].e==1)continue;
			j=find(ds[i].i);k=find(ds[i].j);
			if(j==k)break;
		}
		printf("%s\n",(i>n)?"YES":"NO");
	}
	return 0;
}
