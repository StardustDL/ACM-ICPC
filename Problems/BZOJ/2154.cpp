/*
Crash的数字表格
分析：莫比乌斯反演，GOtohttp://www.cnblogs.com/jianglangcaijin/archive/2013/11/27/3446169.html 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<bitset>
using namespace std;
const int MAXN=10000000,INF=0x3f3f3f3f;
typedef long long LL;
const LL MOD=20101009;
LL n,m;
int miu[MAXN+3];
LL f[MAXN+3];
bitset<MAXN+3> isp;
vector<int> pris;
inline LL sum(LL x,LL y){
	return ((x*(x+1)/2)%MOD)*((y*(y+1)/2)%MOD)%MOD;
}
void pre(){
	miu[1]=1;
	for(LL i=2;i<=min(n,m);i++){
		if(isp[i]==0){
			pris.push_back(i);miu[i]=-1;
		}
		for(LL j=0,k;j<pris.size()&&pris[j]*i<=min(n,m);j++){
			k=pris[j]*i;
			isp[k]=1;
			if(i%pris[j]==0){miu[k]=0;break;}else miu[k]=-miu[i];
		}
	}
	for(LL i=1;i<=min(n,m);i++)f[i]=(f[i-1]+i*i%MOD*miu[i]%MOD)%MOD;
}
LL calc(LL x,LL y){
	LL ans=0,last;//cout<<last<<endl;
	for(LL i=1;i<=min(x,y);i=last+1){
		last=min(x/(x/i),y/(y/i));
		ans=(ans+(f[last]-f[i-1])*sum(x/i,y/i)%MOD)%MOD;
	}
	return ans;
}
LL solve(){
	LL ans=0,last;
	for(LL i=1;i<=min(n,m);i=last+1){
		last=min(n/(n/i),m/(m/i));
		ans=(ans+(((i+last)*(last-i+1)/2)%MOD)*calc(n/i,m/i)%MOD)%MOD;
	}
	return ans;
}
int main(){
	cin>>n>>m;
	pre();
	cout<<(solve()+MOD)%MOD<<endl;
	return 0;
}

