/*
Cow Exhibition
题意：现有N个物品，第i个物品有两个属性A_i和B_i。在其中选取若干个物品，使得sum{A_i + B_i}最大，同时sum{A_i}，sum{B_i}均非负（sum{}表示求和）。  
分析：分析题目中的量：i,suma,sumb
	  将suma看成体积，sumb看成价值，则可视为零一背包问题 
	  但注意suma有负数，对于负体积的转移，将循环反过来做就行了
	  这样就完成了，注意维护可行区间mx,mn,和初始化最小值，f[0]=0
	  一个不用区间右移的方法：使用一个指针，指向数组中间 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=100,MAXV=100*1000+10,INF=0x3f3f3f3f;
int mn=0,mx=0,n,a[MAXN+3],b[MAXN+3],opt[MAXV+3],ans=0;
int *f=&opt[MAXV/2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)if(a[i]>0)mx+=a[i];else mn+=a[i];
	for(int i=mn;i<=mx;i++)f[i]=-INF;
	f[0]=0;mx=mn=0;
	for(int i=1;i<=n;i++){
		if(a[i]>0)
			for(int j=(mx+=a[i]);j-a[i]>=mn;j--)
				f[j]=max(f[j],f[j-a[i]]+b[i]);
		else
			for(int j=(mn+=a[i]);j-a[i]<=mx;j++)
				f[j]=max(f[j],f[j-a[i]]+b[i]);
	}
	for(int i=0;i<=mx;i++)
		if(f[i]>=0)ans=max(f[i]+i,ans);
	printf("%d\n",ans); 
	return 0;
}

