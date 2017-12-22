/*
[HAOI2008]硬币购物
分析：dp预处理+容斥原理
	  设F[i]为不考虑每种硬币的数量限制的情况下，得到面值i的方案数。则状态转移方程为
	    F[i]=Sum{F[i-C[k]] | i-C[k]>=0 且 k=1..4}
	    为避免方案重复，要以k为阶段递推，边界条件为F[0]=1，这样预处理的时间复杂度就是O(S)。
	  接下来对于每次询问，根据容斥原理，答案为 得到面值S的不考虑限制的方案数 – 第1种硬币超过限制的方案数 – 第2种硬币超过限制的方案数 – 第3种硬币超过限制的方案数 – 第4种硬币超过限制的方案数 + 第1,2种硬币同时超过限制的方案数 + 第1,3种硬币同时超过限制的方案数 + …… + 第1,2,3,4种硬币全部同时超过限制的方案数。
	  当第1种硬币超过限制时，只要要用到D[1]+1枚硬币，剩余的硬币可以任意分配，所以方案数为 F[ S – (D[1]+1)C[1] ]，
	  当且仅当(S –(D[1]+1)C[1])>=0，否则方案数为0。其余情况类似，每次询问只用问16次，所以询问的时间复杂度为O(1)。
	  这里询问较多，物品较少，适合这种方法。 
	  记着开long long 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100000,INF=0x3f3f3f3f;
int c[5],d[5],n,s;
LL cnt[MAXN+3],ans;
void solve(int ind,int out,int sum){//out，表示超出限制的物品种数，以此判断是加是减 
	if(sum<0)return;
	if(ind==5){
		if(out&1)ans-=cnt[sum];
		else ans+=cnt[sum];
	}
	else{
		solve(ind+1,out+1,sum-(d[ind]+1)*c[ind]);
		solve(ind+1,out,sum);
	}
}
int main(){
	for(int i=1;i<=4;i++)scanf("%d",&c[i]);
	cnt[0]=1;
	for(int i=1;i<=4;i++)
		for(int j=c[i];j<=MAXN;j++)
			cnt[j]+=cnt[j-c[i]];
	for(scanf("%d",&n);n;n--){
		for(int i=1;i<=4;i++)scanf("%d",&d[i]);
		scanf("%d",&s);
		ans=0;solve(1,0,s);
		printf("%lld\n",ans);
	}
	return 0;
}

