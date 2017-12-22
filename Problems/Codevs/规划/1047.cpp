/*
邮票面值设计
分析：是邮票问题的升级版，先DFS出一个结果，然后DP求其最大值，
	  生成结果时注意：如果邮票张数为n，种类为k,那么从小到大的顺序，邮票a[i]的下一种面值的取值范围必然是a[i]+1到a[i]*n+1
	  注意在程序中n和k的区分 
*/
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
const int MAXN=40;
int n,k,a[MAXN+3],opt[MAXN*100000+3],an[MAXN+3],mx=0;
int dp(){
	int ans=0;
	do{
		opt[++ans]=n+3;
		for(int i=1;i<=k&&a[i]<=ans;i++)
			opt[ans]=min(opt[ans],opt[ans-a[i]]+1);
	}while(opt[ans]<=n);
	return ans-1;
}
void dfs(int d){
	if(d>k){
		int ans=dp();
		if(ans>mx){
			mx=ans;
			memcpy(an,a,(k+3)*sizeof(int));
		}
		return;
	}
	for(int i=a[d-1]+1;i<=a[d-1]*n+1;i++){
		a[d]=i;dfs(d+1);
	}
}
int main(){
	cin>>n>>k;
	dfs(1);
	for(int i=1;i<=k;i++)cout<<an[i]<<" ";
	cout<<endl<<"MAX="<<mx;
	return 0;
}
