/*
[SCOI2009]���տ���
����������������һ��Ҫ�ȷ֣�ö�������Ｔ�� 
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
		ans=min(ans,max(dfs(x/n*i,y,i),dfs(x/n*(n-i),y,n-i)));//��x 
		ans=min(ans,max(dfs(x,y/n*i,i),dfs(x,y/n*(n-i),n-i)));//��y 
	}
	return ans;
}
int main(){
	int x,y,n;
	scanf("%d%d%d",&x,&y,&n);
	printf("%.6lf",dfs(x,y,n));
	return 0;
}

