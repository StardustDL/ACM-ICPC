/*
[SCOI2009]生日快乐
分析：暴力搜索，一定要等分，枚举切哪里即可 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
double dfs(double x,double y,int n){
	if(x<y)swap(x,y);
	if(n==1)return x/y;
	double ans=INF;
	for(int i=1;i<n;i++){
		ans=min(ans,max(dfs(x/n*i,y,i),dfs(x/n*(n-i),y,n-i)));//切x 
		ans=min(ans,max(dfs(x,y/n*i,i),dfs(x,y/n*(n-i),n-i)));//切y 
	}
	return ans;
}
int main(){
	int x,y,n;
	scanf("%d%d%d",&x,&y,&n);
	printf("%.6lf",dfs(x,y,n));
	return 0;
}

