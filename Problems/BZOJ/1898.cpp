/*
[Zjoi2004]Swamp 沼泽鳄鱼  
分析：矩阵乘法，现在有一堆鱼，导致每次转移不太一样
		然后发现鱼的周期的lcm=12很小，所以转移是每12次为一周期的
		所以矩阵转移一下整的周期，不完整的周期暴力转移一下就好了 
		注意矩阵乘法不满足交换律！！！ 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f,MOD=10000;
struct matrix{
	int a[55][55],n,m;
	void clear(){memset(a,0,sizeof(a));}
	int* operator [](const int &d){
		return a[d];
	}
};
void mulply(matrix &a,matrix &b,matrix &c){
	static matrix t;
	t.n=a.n;t.m=b.m;
	for(int i=1;i<=a.n;i++){
		for(int j=1;j<=b.m;j++){
			t[i][j]=0;
			for(int k=1;k<=a.m;k++)(t[i][j]+=a[i][k]*b[k][j])%=MOD;
		}
	}
	c=t;
}
void ksm(matrix a,int n,matrix &c){
	static matrix t;
	t.n=a.n;t.m=a.m;
	for(int i=1;i<=a.n;i++)for(int j=1;j<=a.m;j++)t[i][j]=(i==j);
	while(n){
		if(n&1)mulply(t,a,t);
		mulply(a,a,a);
		n>>=1;
	}
	c=t;
}
int n,m,start,end,K,nf,tmp[10];
matrix w[15],ans;
int main(){
	scanf("%d%d%d%d%d",&n,&m,&start,&end,&K);start++;end++;
	ans.n=n;ans.m=1;ans.clear();ans[start][1]=1;
	w[1].n=w[1].m=n;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);x++,y++;
		w[1][x][y]++;w[1][y][x]++;
	}
	for(int i=2;i<=12;i++)w[i]=w[1];
	scanf("%d",&nf);
	for(int i=1,T;i<=nf;i++){
		scanf("%d",&T);
		for(int j=0;j<T;j++)scanf("%d",&tmp[j]);
		for(int j=1;j<=12;j++){
			int v=tmp[j%T]+1;
			for(int k=1;k<=n;k++){
				w[j][v][k]=0;
			}
		}
	}
	for(int i=2;i<=12;i++)mulply(w[i],w[i-1],w[i]);
	ksm(w[12],K/12,w[0]);
	if(K%12)mulply(w[K%12],w[0],w[0]);
	mulply(w[0],ans,ans);
	printf("%d\n",ans[end][1]);
	return 0;
}

