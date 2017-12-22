/*

*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=60;
int n,a[MAXN+3],ans,sum;
bitset<MAXN+3> use;
bool dfs(int p,int cur){
	if(cur>ans)return false;
	if(cur==ans)return true;
	for(int i=p;i<=n;i++)if(!use[i]&&cur+a[i]<=ans){
		use[i]=1;
		if(dfs(i+1,cur+a[i]))return true;
		use[i]=0;
	}
	return false;
}
bool check(){
	use=0;
	for(int t=sum/ans;t;t--)if(!dfs(1,0))return false;
	return true;
}
int main(){
	int T;scanf("%d",&T);n=1;
	for(int i=1;i<=T;i++){
		scanf("%d",&a[n]);
		if(a[n]<=50)n++;
	}
	if(!a[n])n--;
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)sum+=a[i];
	for(int i=a[n];i<=sum;i++){ 
		if(sum%i!=0)continue;
		ans=i;if(check())break;
	}
	printf("%d\n",ans);
	return 0;
}

