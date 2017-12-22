/*
BUY LOW, BUY LOWER
题意：求最长严格下降子序列，并求出子序列的种数。
分析：关键在计数，计数关键在于不重复，注意是不同种，所以当值相等时应只记录一次 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=5000;
int opt[MAXN+3],n,a[MAXN+3],cnt[MAXN+3]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]); 
	for(int i=1;i<=n;i++){
		opt[i]=1;cnt[i]=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]<a[j]){
				if(opt[j]+1>opt[i]){
					opt[i]=opt[j]+1;
					cnt[i]=cnt[j];
				}
				else if(opt[j]+1==opt[i])cnt[i]+=cnt[j];
			}
			else if(a[i]==a[j])cnt[j]=0;//当a值相等时，排在前面的实际上已经无效了因为后面的肯定更优，所以cnt值置0，因为序列相同时次数不叠加。  
		}
	}
	int ans=0,cts=0;
	for(int i=1;i<=n;i++)ans=max(ans,opt[i]);
	for(int i=1;i<=n;i++)if(opt[i]==ans)cts+=cnt[i];
	printf("%d %d",ans,cts);
	return 0;
}

