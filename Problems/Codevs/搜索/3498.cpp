/*
Ð¡Ä¾¹÷
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=60;
int n,a[MAXN+3],ans,sum,mx=0;
bitset<MAXN+3> use;
bool dfs(int p,int cur){
	if(cur>ans)return false;
	use[p]=1;
	if(cur==ans)return true;
	for(int i=p-1;i;i--)if(!use[i]&&dfs(i,cur+a[i]))return true;
	use[p]=0;
	return false;
}
bool check(){
	use=0;
	for(int t=sum/ans;t;t--)if(!dfs(n+1,0))return false;
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	while(a[n]>100&&n)n--;
	for(int i=1;i<=n;i++)sum+=a[i],mx=max(mx,a[i]);
	for(int i=mx;i<=sum;i++){ 
		if(sum%i!=0)continue;
		ans=i;if(check())break;
	}
	printf("%d\n",ans);
	return 0;
}

