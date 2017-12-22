/*
[HNOI2007]梦幻岛宝珠
分析：考虑到每个weight都能写成a*2^b的形式，显然我们要按照b分层来进行背包
	  那么令f[i][j]存储第i层的背包 ，即f[i][j]表示有j*2^i的空间时，只使用重量为a*2^i的物品的最大价值
	  接下来处理层与层的转移，重新定义状态——f[i][j]表示有j*2^i+(w&(1<<i)-1)的空间时的最大价值，这样考虑W和子层 
	  枚举当前层留下多少空间给下一层，这样设给下一层的是k，那么下一层的状态就是[2*k+(w第i-1位是否为1)] 
	  所以转移：f[i][j]=max(f[i][j-k]+f[i-1][k*2+(w>>(i-1)&1)]) 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
typedef long long LL;
const LL UP=MAXN*10;
int n; 
LL f[33][UP+3],ans=0,W;
int main(){
	while(scanf("%d%lld",&n,&W)){
		if(n==-1&&W==-1)break;
		memset(f,0,sizeof(f));
		ans=0;
		for(int w,v,i=1;i<=n;i++){
			scanf("%d%d",&w,&v);
			int b=0;while(!(w&1))++b,w>>=1;
			for(int j=UP;j>=w;j--)f[b][j]=max(f[b][j],f[b][j-w]+v);
		}
		ans=f[0][UP];
		for(int i=1;i<=30&&(1LL<<i)<=W;i++){
			for(int j=min(W>>i,UP);~j;j--){
				for(int k=0;k<=j;k++)f[i][j]=max(f[i][j],f[i][j-k]+f[i-1][min(k*2+((W>>i-1)&1),UP)]);
				ans=max(ans,f[i][j]);
			}
		}
		printf("%lld\n",ans); 
	}
	return 0;
}

