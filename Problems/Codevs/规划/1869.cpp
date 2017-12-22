/*
硬币购物
分析：第一次做容斥原理，看了题解才明白
	  dp预处理+容斥原理
	  设F[i]为不考虑每种硬币的数量限制的情况下，
	  得到面值i的方案数。则状态转移方程为
	  F[i]=Sum{F[i-C[k]] | i-C[k]>=0 且 k=1..4}
	  为避免方案重复，要以k为阶段递推，边界条件为F[0]=1，这样预处理的时间复杂度就是O(S)。
	  接下来对于每次询问，奇妙的解法如下：
	  根据容斥原理，答案为 
	  得到面值S的超过限制的方案数
	   - 第1种硬币超过限制的方案数 - 第2种硬币超过限制的方案数 - 第3种硬币超过限制的方案数 - 第4种硬币超过限制的方案数
	    + 第1,2种硬币同时超过限制的方案数 + 第1,3种硬币同时超过限制的方案数 + ...... + 第1,2,3,4种硬币全部同时超过限制的方案数。
	  当第1种硬币超过限制时，只要要用到D[1]+1枚硬币，
	  剩余的硬币可以任意分配，
	  所以方案数为 F[ S - (D[1]+1)C[1] ]，
	  当且仅当(S - (D[1]+1)C[1])>=0，
	  否则方案数为0。其余情况类似，
	  每次询问只用问16次，所以询问的时间复杂度为O(1)。 
	  还有，一定要开long long  
*/
#include<iostream>
using namespace std;
const int MAXN=100000;
typedef long long LL; 
int n,c[5],k[5];
LL cnt[MAXN+3],ans;
void dfs(int ind,int ct,int sum){
	if(sum<0)return;
	if(ind>4){
		if(ct&1){//奇数为减
			 ans-=cnt[sum];
		}
		else ans+=cnt[sum];
		return;
	}
	dfs(ind+1,ct+1,sum-(k[ind]+1)*c[ind]);//含有ind项的 
	dfs(ind+1,ct,sum);//不含ind项的 
}
int main(){
	cin>>c[1]>>c[2]>>c[3]>>c[4]>>n;
	cnt[0]=1;
	for(int i=1;i<=4;i++)
		for(int j=c[i];j<=MAXN;j++)
			cnt[j]+=cnt[j-c[i]];
	while(n-->0){
		cin>>k[1]>>k[2]>>k[3]>>k[4]>>k[0];
		ans=0;
		dfs(1,0,k[0]);
		cout<<ans<<endl; 
	}
	return 0;
}
