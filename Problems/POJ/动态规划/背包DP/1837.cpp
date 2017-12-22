/*
Balance 
题意：有一个天平，天平左右两边各有若干个钩子，总共有C个钩子，有G个钩码，求将钩码全部挂到钩子上使天平平衡的方法的总数。，其中可以把天枰看做一个以x轴0点作为平衡点的横轴
分析：每向天平中方一个重物，天平的状态就会改变，而这个状态可以由若干前一状态获得。
	  首先定义一个平衡度j的概念
	  当平衡度j=0时，说明天枰达到平衡，j>0，说明天枰倾向右边（x轴右半轴），j<0则相反
	  那么此时可以把平衡度j看做为衡量当前天枰状态的一个值
	  因此可以定义一个 状态数组dp[i][j]，意为在挂满前i个钩码时，平衡度为j的挂法的数量。
	  由于距离c[i]的范围是-15~15，钩码重量的范围是1~25，钩码数量最大是20
	  因此最极端的平衡度是所有物体都挂在最远端，因此平衡度最大值为j=15*20*25=7500。原则上就应该有dp[ 1~20 ][-7500 ~ 7500 ]。
	  状态方程dp[i][ j+ w[i]*c[k] ]= ∑（dp[i-1][j]）
	  dp[0][7500] = 1;   //不挂任何重物时天枰平衡，此为一个方法
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXV=7500,MAXN=20,INF=0x3f3f3f3f;
int _f[2][MAXV+3<<1],*opt[2],n,g,p[MAXN+3],w[MAXN+3],cur;
int main(){
	opt[0]=&_f[0][MAXV];opt[1]=&_f[1][MAXV];
	scanf("%d%d",&n,&g);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=g;i++)scanf("%d",&w[i]);
	memset(_f,0,sizeof(_f));
	opt[cur=0][0]=1;
	for(int i=1,t;i<=g;i++,cur^=1){//枚举钩码 
		memset(_f[cur^1],0,sizeof(_f[cur^1]));
		for(int j=-MAXV;j<=MAXV;j++)//枚举状态
			if(opt[cur][j]){
				for(int k=1;k<=n;k++)//枚举位置 
					if((t=j+p[k]*w[i])>=-MAXV&&t<=MAXV)opt[cur^1][t]+=opt[cur][j];
			}
	}
	printf("%d\n",opt[cur][0]);
	return 0;
}

