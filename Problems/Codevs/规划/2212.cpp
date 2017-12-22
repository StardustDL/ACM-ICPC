/*
任务安排
分析：注意到“每批包含相邻的若干任务”，可以用DP解决
	  用opt[i]表示前i个任务的最优解，
	  转移为opt[i]=min{opt[k]+s*(f[n]-f[k])+t[i]*(f[i]-f[k])|0<=k<i}
	  其中f[n]表示费用系数前缀和，t[i]表示前i个任务的时间总和
	  转移方程分为3部分：
	  	opt[k]:之前的最优解
		s*(f[n]-f[k]):由于机器启动导致的后[k+1..n]任务的费用增加
		t[i]*(f[i]-f[k]):第[k+1..i]任务的费用，不含s 
	  注意边界opt[0]=0 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5000,INF=0x3f3f3f3f;
int n,opt[MAXN+3],t[MAXN+3],f[MAXN+3],s;
void input(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>f[i];
		t[i]+=t[i-1];
		f[i]+=f[i-1];
	}
}
int dp(){
	memset(opt,INF,sizeof(opt));
	opt[0]=0;
	for(int i=1;i<=n;i++){
		for(int k=0;k<i;k++){
			opt[i]=min(opt[i],opt[k]+s*(f[n]-f[k])+t[i]*(f[i]-f[k]));
		}
	}
	return opt[n];
}
int main(){
	input();
	cout<<dp();
	return 0;
} 
