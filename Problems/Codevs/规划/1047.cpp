/*
��Ʊ��ֵ���
����������Ʊ����������棬��DFS��һ�������Ȼ��DP�������ֵ��
	  ���ɽ��ʱע�⣺�����Ʊ����Ϊn������Ϊk,��ô��С�����˳����Ʊa[i]����һ����ֵ��ȡֵ��Χ��Ȼ��a[i]+1��a[i]*n+1
	  ע���ڳ�����n��k������ 
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
