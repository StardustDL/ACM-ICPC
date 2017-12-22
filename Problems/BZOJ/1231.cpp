/*
[Usaco2008 Nov]mixup2 混乱的奶牛
分析：N很小，状压DP 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,k,s[16+3]; 
long long f[1<<18][18];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&s[i]);
	for(int i=0;i<n;i++)f[1<<i][i]=1;
	for(int st=0;st<(1<<n);st++){
		for(int i=0;i<n;i++){
			if((st&(1<<i))&&f[st][i]){
				for(int j=0;j<n;j++){
					if((st&(1<<j))||abs(s[j]-s[i])<=k)continue;
					f[st|(1<<j)][j]+=f[st][i];
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<n;i++)ans+=f[(1<<n)-1][i];
	printf("%lld\n",ans);
	return 0;
}

