/*
[SCOI2009]游戏
分析：这道题可以转换一下。
		试想每一个对应关系a-b为从a->b的一条边，
		那么图中一定存在n条边且每个点入度出度都为1，
		易证一定存在一个或几个环。
		实际上排数就是这几个环大小的最小公倍数。
		即求：和为n的数列的最小公倍数种数。
		那么可以直接DP：
		预处理质数表，opt[j]表示组成和=j的数列的LCM种数，
		有opt[j]=opt[j]+opt[j-p]+opt[j-p*p]+opt[j-p^3]+...(each p <= n)
		我们只要保证和<=n即可，因为余下部分用1补即可。
		ans=sigma(0<=i<=n,opt[i]) 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<bitset>
using namespace std;
typedef unsigned long long ULL;
const int MAXN=1000,INF=0x3f3f3f3f;
ULL opt[2][MAXN+3];
vector<int> pris;
bitset<MAXN+3> isp;
void init(int size){
	isp=0;
	for(int i=2;i<=size;i++){
		if(isp[i])continue;
		pris.push_back(i);
		for(int j=i*i;j<=size;j+=i)isp[j]=1;
	}
}
ULL solve(int n){
	memset(opt,0,sizeof(opt));int cur=0;opt[0][0]=1;
	for(int i=0;i<pris.size();i++,cur^=1){
		//cout<<pris[i]<<endl;
		memcpy(opt[cur^1],opt[cur],sizeof(opt[cur^1]));//注意这里的复制 
		for(int p=pris[i];p<=n;p*=pris[i])
			for(int j=p;j<=n;j++)
				opt[cur^1][j]+=opt[cur][j-p];
	}
	ULL ans=0;
	for(int i=0;i<=n;i++)ans+=opt[cur][i];
	return ans;
}
int n;
int main(){
	cin>>n;
	init(n);
	cout<<solve(n)<<endl;
	return 0;
}

