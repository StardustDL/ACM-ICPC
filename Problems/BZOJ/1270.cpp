/*
[BeijingWc2008]���ε�Сè
������DP���������ݷ�Χ��ʲô��= = 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5000,INF=0x3f3f3f3f;
int mp[MAXN+3][MAXN+3];
int dp[MAXN+3],c[MAXN+3],n,h,d; //�߶�Ϊi���ֵ����ǰ�߶��ڵ�i�������ֵ 
int main(){
	scanf("%d%d%d",&n,&h,&d);
	for(int i=1;i<=n;i++){
		int t,x;scanf("%d",&t);
		for(;t;t--){
			scanf("%d",&x);
			mp[i][x]++;
		}
	}
	for(int i=h;i;i--){
		int up=(i+d<=h)?dp[i+d]:0;//���Ϸ������� 
		for(int j=1;j<=n;j++){
			c[j]=max(c[j],up)+mp[j][i]; 
		}
		dp[i]=max(dp[i],*max_element(c+1,c+n+1));
	}
	printf("%d\n",dp[1]);
	return 0;
}

