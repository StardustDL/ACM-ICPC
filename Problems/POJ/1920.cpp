/*
Towers of Hanoi
题意：已给一个汉诺塔的摆放状态，要你求出现在这个状态下，到达最终的结果状态即从小到上方块递减。所用的移动次数最少。最终状态可以在任意一个铁杆下。要求输出最终状态所在的铁杆号和最小移动步数 
分析：最终状态所在的铁杆号就是当前给出的状态中最大方块所在的杆。可以反过来看，从最终状态到现在这个摆放状态所要求移动的最小步数
	  问题转化后：由一根柱子上的1..n转移到一个新的状态，注意一个贪心策略：肯定不会去移动最大的那一个，因为要移动最大的一个步数是把其他所有的移一遍的总和加1
	  所以反过来之后就变成每次一定先将当前最大的移到正确位置，怎么移动呢？先将其上的i-1个移到另一个杆子上，再将第i个移到剩下的那根杆子上，再去处理剩下的1..i-1个杆子
	  利用Hanoi的结论：a(n) = 2^n - 1，就是位于一根杆子的1..n的方块移动到另外一个杆子所用的最少步数 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000,MOD=1000000;
int stp[MAXN+3],cur,n,cnt[3],t,pos[MAXN+3],ans; 
int main(){
	stp[0]=0;
	for(int i=1;i<=MAXN;i++)stp[i]=((stp[i-1]<<1)+1)%MOD;
	while(scanf("%d",&n)!=EOF){
		scanf("%d%d%d",&cnt[0],&cnt[1],&cnt[2]);
		for(int i=0;i<3;i++){
			for(int j=1;j<=cnt[i];j++){
				scanf("%d",&t);
				pos[t]=i+1;
			}
		}
		cur=pos[n];ans=0;
		for(int i=n;i>=1;i--){
			if(cur!=pos[i]){
				cur=6-pos[i]-cur;
				(ans+=stp[i-1]+1)%=MOD;
			}
		}
		printf("%d\n%d\n",pos[n],ans);
	}
	return 0;
}

